#include "Character.h"


Character::Character(){
	character = '@';
	name = "Zorak Warslayer";
	movement = NULL;
	xPos = NULL;
	yPos = NULL;
	racialAlignment = evil;
	backpack = new Inventory;
	paperdoll = new Paperdoll;
	stats = new CharacterStats;
	backpack->inventory.push_back(new Leafblade());
	backpack->inventory.push_back(new DragonChest());
}

Character::~Character(){
	delete backpack;
	delete paperdoll;
	delete stats;
}

Character::Character(int x, int y){
	character = '@';
	name = "Zorak Warslayer";
	movement = NULL;
	xPos = x;
	yPos = y;
	racialAlignment = evil;
	backpack = new Inventory;
	paperdoll = new Paperdoll;
	stats = new CharacterStats;
	backpack->inventory.push_back(new Leafblade());
	backpack->inventory.push_back(new DragonChest());

}

void Character::setPos(int x, int y){
	xPos = x;
	yPos = y;
}

char Character::getChar(){
	return character;
}

bool Character::isMovement(char m){
	if (m == 'l' || m == 'k' || m == 'j' || m == 'h' ||
		m == 'y' || m == 'u' || m == 'b' || m == 'n')
		return true;
	else return false;
}

string Character::moveChar(char m){
	stringstream ss;
	if (isMovement(m)){
		movement = m;
	}
	else if (m == 'p')
		ss << paperdoll->printPaperdoll();
	else if (m == 'i')
		ss << backpack->printInv();
	else if (m == 'e')
		ss << putOnGear();
	else if (m == 'I')
		ss << examineItem();
	else if (m == 's')
		ss << stats->printStats();
	else if (m == 'S')
		ss << stats->printFullStats();
	else movement = NULL;
	return ss.str();
}

char Character::getMovement(){
	return movement;
}

int Character::getXpos(){
	return xPos;
}

int Character::getYpos(){
	return yPos;
}

float Character::getHP(){
	return stats->getHP();
}

string Character::getName(){
	return name;
}

string Character::equip(Item *equippable, bool &result){
	// Check to see if it's in the characters backpack
	stringstream ss;
	for (int i = 0; i < backpack->inventory.size(); i++){
		if (equippable->getItemID() == backpack->inventory[i]->getItemID()){
			if (equippable->equipped){
				ss << equippable->getName() << " is already equipped." << endl;
				result = false;
				return ss.str();
			}
			else{
				ss << equippable->equip(this);
				result = true;
				return ss.str();
			}
		}

	}
	result = false;
	return ss.str();
}

string Character::examineItem(){
	stringstream ss;
	cout << backpack->printInv();
	cout << "Which item would you like to examine? Q to not examine any. " << endl << endl;
	char input = _getch();
	if (input == 'Q') return "";
	int pos = 0;
	if (input >= 97 && input <= 122)
		pos = (input - 87);
	else if (input >= 48 && input <= 57)
		pos = (input - 48);
	if (pos < backpack->inventory.size()){
		Item *temp = backpack->inventory[pos];
		ss << temp->examine();
	}
	return ss.str();
}

string Character::putOnGear(){
	stringstream ss;
	cout << backpack->printInv();
	cout << "Press Q to not put on gear." << endl;
	char input = _getch();
	if (input == 'Q') return "";
	int pos = 0;
	if (input >= 97 && input <= 122)
		pos = (input - 87);
	else if (input >= 48 && input <= 57)
		pos = (input - 48);
	if (pos < backpack->inventory.size()){
		Item *temp = backpack->inventory[pos];
		bool result = false;
		ss << equip(temp, result);
		if(result)
			updateProts();
	}
	return ss.str();
}

void Character::updateProts(){
	stats->resetProts();
	stats->resetEncumbrance();
	stats->addProts(paperdoll->boots);
	stats->addProts(paperdoll->chest);
	stats->addProts(paperdoll->elbows);
	stats->addProts(paperdoll->gauntlets);
	stats->addProts(paperdoll->girdle);
	stats->addProts(paperdoll->greaves);
	stats->addProts(paperdoll->helm);
	stats->addProts(paperdoll->legs);
	stats->addProts(paperdoll->lhRing);
	stats->addProts(paperdoll->necklace);
	stats->addProts(paperdoll->rhRing);
	stats->addProts(paperdoll->robe);
	stats->addProts(paperdoll->shield);
	stats->addProts(paperdoll->shoulders);
	stats->addProts(paperdoll->vambraces);

}

//This interacts with c
string Character::interactCharacter(Character* c){
	stringstream ss;
	if (c == NULL)
		return "";
	if (this->racialAlignment != c->racialAlignment || this->racialAlignment == evil || c->racialAlignment == evil){
		ss << this->calculateMeleeDamage(c);
	}
	return ss.str();
}

//Takes weapon damage multiplies it by character strength, adds 1 damage per 10 weapon rank, then adds a flat 8 damage.
//Will be more complex once weapon skills/masteries/passives and such.
string Character::calculateMeleeDamage(Character* c){
	stringstream ss;
	if (this->paperdoll->primary == NULL){
		ss << "There's no weapon to attack with! " << endl;
		return ss.str();
	}
	float damage = this->paperdoll->primary->getDamage();
	damage *= this->stats->getStr();
	damage += (this->paperdoll->primary->getWeaponRank() / 10);
	damage += 8;
	Damage incDamage;
	incDamage.damage = damage;
	incDamage.damageType = this->paperdoll->primary->getDamageType();
	
	ss << c->damage(incDamage);

	return ss.str();
}

string Character::damage(Damage incDamage){
	stringstream ss;
	switch (incDamage.damageType){
	case slashing:
		incDamage.damage -= this->stats->getProtSlashing();
	case piercing:
		incDamage.damage -= this->stats->getProtPiercing();
	case bludgeoning:
		incDamage.damage -= this->stats->getProtBludgeoning();
	case arrow:
		incDamage.damage -= this->stats->getProtArrow();
	}

	this->stats->damage(incDamage);
	ss << this->name << "'s HP is now: " << this->stats->getHP() << endl;
	return ss.str();
}

Goblin::Goblin() : Character(){
	name = "Goblin";
	character = 'g';
	racialAlignment = monster;
	backpack->inventory.clear();
	stats->setHP(50);
	stats->setStam(50);
	stats->setMana(50);
	stats->setStr(15);
	stats->setVit(15);
	stats->setDex(15);
	stats->setQuick(15);
	stats->setIntel(10);
	stats->setWis(10);

}

Goblin::~Goblin(){

}