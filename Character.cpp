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

void Character::moveChar(char m){
	if (isMovement(m)){
		movement = m;
	}
	else if (m == 'p')
		paperdoll->printPaperdoll(); // +		paperdoll	0x005bbd28 
	else if (m == 'i')
		backpack->printInv();
	else if (m == 'e')
		putOnGear();
	else if (m == 'I')
		examineItem();
	else if (m == 's')
		stats->printStats();
	else if (m == 'S')
		stats->printFullStats();
	else movement = NULL;
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

bool Character::equip(Item *equippable){
	// Check to see if it's in the characters backpack
	for (int i = 0; i < backpack->inventory.size(); i++){
		if (equippable->getItemID() == backpack->inventory[i]->getItemID()){
			if (equippable->equipped){
				cout << equippable->getName() << " is already equipped." << endl;
				return false;
			}
			equippable->equip(this);
			return true;
		}

	}
	return false;
}

void Character::examineItem(){
	backpack->printInv();
	cout << "Which item would you like to examine? Q to not examine any. " << endl << endl;
	char input = _getch();
	if (input == 'Q') return;
	int pos = 0;
	if (input >= 97 && input <= 122)
		pos = (input - 87);
	else if (input >= 48 && input <= 57)
		pos = (input - 48);
	if (pos < backpack->inventory.size()){
		Item *temp = backpack->inventory[pos];
		temp->examine();
	}
}

void Character::putOnGear(){
	backpack->printInv();
	cout << "Press Q to not put on gear." << endl;
	char input = _getch();
	if (input == 'Q') return;
	int pos = 0;
	if (input >= 97 && input <= 122)
		pos = (input - 87);
	else if (input >= 48 && input <= 57)
		pos = (input - 48);
	if (pos < backpack->inventory.size()){
		Item *temp = backpack->inventory[pos];
		if(equip(temp))
			updateProts();
	}
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
void Character::interactCharacter(Character* c){
	if (c == NULL)
		return;
	if (this->racialAlignment != c->racialAlignment || this->racialAlignment == evil || c->racialAlignment == evil){
		this->calculateMeleeDamage(c);
	}
}

//Takes weapon damage multiplies it by character strength, adds 1 damage per 10 weapon rank, then adds a flat 8 damage.
//Will be more complex once weapon skills/masteries/passives and such.
void Character::calculateMeleeDamage(Character* c){
	if (this->paperdoll->primary == NULL){
		cout << "There's no weapon to attack with! " << endl;
		system("PAUSE");
		return;
	}
	float damage = this->paperdoll->primary->getDamage();
	damage *= this->stats->getStr();
	damage += (this->paperdoll->primary->getWeaponRank() / 10);
	damage += 8;
	Damage incDamage;
	incDamage.damage = damage;
	incDamage.damageType = this->paperdoll->primary->getDamageType();
	
	c->damage(incDamage);
}

void Character::damage(Damage incDamage){
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
	cout << this->name << "'s HP is now: " << this->stats->getHP() << endl;
	system("PAUSE");

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