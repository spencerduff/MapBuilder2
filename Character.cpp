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
	ai = NULL;
	backpack->inventory.push_back(new Leafblade(backpack));
	backpack->inventory.push_back(new DragonChest(backpack));
	backpack->inventory.push_back(new Bile(backpack));
	backpack->inventory.push_back(new Cinder(backpack));
	backpack->inventory.push_back(new Darktaint(backpack));
	backpack->inventory.push_back(new Numen(backpack));

}

Character::~Character(){
	delete stats;
	delete ai;
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
	ai = NULL;
	backpack->inventory.push_back(new Leafblade(backpack));
	backpack->inventory.push_back(new DragonChest(backpack));

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
	else if (m == 'f')
		movement = m;
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

AI* Character::getAI(){
	return ai;
}

void Character::setMovement(char m){
	if (isMovement(m))
		this->movement = m;
}

string Character::equip(Item *equippable, bool &result){
	// Check to see if it's in the characters backpack
	stringstream ss;
	for (unsigned int i = 0; i < backpack->inventory.size(); i++){
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
	int pos = backpack->parsePosInBackpack(input);
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
	int pos = backpack->parsePosInBackpack(input);
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

	float calcHits = this->paperdoll->primary->getSpeed();
	calcHits *= (this->stats->getQuick() / 10);
	int hits = calcHits;
	if (calcHits < 1)
		hits = 1;

	Damage incDamage;
	incDamage.damage = damage;
	incDamage.damageType = this->paperdoll->primary->getDamageType();
	incDamage.numOfHits = hits;
	
	ss << c->damage(incDamage);

	this->paperdoll->primary->decrementDura();

	return ss.str();
}

string Character::damage(Damage incDamage){
	stringstream ss;
	switch (incDamage.damageType){
	case slashing:
		incDamage.damage -= this->stats->getProtSlashing();
		break;
	case piercing:
		incDamage.damage -= this->stats->getProtPiercing();
		break;
	case bludgeoning:
		incDamage.damage -= this->stats->getProtBludgeoning();
		break;
	case arrow:
		incDamage.damage -= this->stats->getProtArrow();
		break;
	}
	this->damageArmor();

	if (incDamage.damage < 0)
		incDamage.damage = 0;
	this->stats->damage(incDamage);
	ss << this->name << "'s HP is now: " << this->stats->getHP() << " after " << incDamage.numOfHits;
	if (incDamage.numOfHits == 1)
		ss << " hit." << endl;
	else
		ss << " hits." << endl;
	return ss.str();
}

void Character::damageArmor(){
	bool notDamaged = true;
	int tries = 30;
	while (notDamaged && tries--){
		int toDamage = rand() % 15; //15 is number of paperdoll slots
		switch ((Piece)toDamage){
		case helm:
			if (this->paperdoll->helm != NULL){
				this->paperdoll->helm->decrementDura();
				notDamaged = false;
			}
			break;
		case chest:
			if (this->paperdoll->chest != NULL){
				this->paperdoll->chest->decrementDura();
				notDamaged = false;	
			}
			break;
		case legs:
			if (this->paperdoll->legs != NULL){
				this->paperdoll->legs->decrementDura();
				notDamaged = false;
			}
			break;
		case greaves:
			if (this->paperdoll->greaves != NULL){
				this->paperdoll->greaves->decrementDura();
				notDamaged = false;
			}
			break;
		case gauntlets:
			if (this->paperdoll->gauntlets != NULL){
				this->paperdoll->gauntlets->decrementDura();
				notDamaged = false;
			}
			break;
		case elbows:
			if (this->paperdoll->elbows != NULL){
				this->paperdoll->elbows->decrementDura();
				notDamaged = false;
			}
			break;
		case boots:
			if (this->paperdoll->boots != NULL){
				this->paperdoll->boots->decrementDura();
				notDamaged = false;
			}
			break;
		case vambraces:
			if (this->paperdoll->vambraces != NULL){
				this->paperdoll->vambraces->decrementDura();
				notDamaged = false;
			}
			break;
		case girdle:
			if (this->paperdoll->girdle != NULL){
				this->paperdoll->girdle->decrementDura();
				notDamaged = false;
			}
			break;
		case shoulders:
			if (this->paperdoll->shoulders != NULL){
				this->paperdoll->shoulders->decrementDura();
				notDamaged = false;
			}
			break;
		case necklace:
			if (this->paperdoll->necklace != NULL){
				this->paperdoll->necklace->decrementDura();
				notDamaged = false;
			}
			break;
		case ring:
			if (this->paperdoll->rhRing != NULL && this->paperdoll->lhRing != NULL){
				if (rand()%2)
					this->paperdoll->rhRing->decrementDura();
				else this->paperdoll->lhRing->decrementDura();
				notDamaged = false;
			}
			else if (this->paperdoll->rhRing != NULL){
				this->paperdoll->rhRing->decrementDura();
				notDamaged = false;
			}
			else if (this->paperdoll->lhRing != NULL){
				this->paperdoll->lhRing->decrementDura();
				notDamaged = false;
			}
			break;
		case earring:
			if (this->paperdoll->earring != NULL){
				this->paperdoll->earring->decrementDura();
				notDamaged = false;
			}
			break;
		case robe:
			if (this->paperdoll->robe != NULL){
				this->paperdoll->robe->decrementDura();
				notDamaged = false;
			}
			break;
		case shield:
			if (this->paperdoll->shield != NULL){
				this->paperdoll->shield->decrementDura();
				notDamaged = false;
			}
			break;
		}
	}

}

void Character::unequipAll(){
	paperdoll->unequip(paperdoll->boots);
	paperdoll->unequip(paperdoll->chest);
	paperdoll->unequip(paperdoll->earring);
	paperdoll->unequip(paperdoll->elbows);
	paperdoll->unequip(paperdoll->gauntlets);
	paperdoll->unequip(paperdoll->girdle);
	paperdoll->unequip(paperdoll->greaves);
	paperdoll->unequip(paperdoll->helm);
	paperdoll->unequip(paperdoll->legs);
	paperdoll->unequip(paperdoll->lhRing);
	paperdoll->unequip(paperdoll->necklace);
	paperdoll->unequip(paperdoll->primary);
	paperdoll->unequip(paperdoll->quiver);
	paperdoll->unequip(paperdoll->rhRing);
	paperdoll->unequip(paperdoll->robe);
	paperdoll->unequip(paperdoll->shield);
	paperdoll->unequip(paperdoll->shoulders);
	paperdoll->unequip(paperdoll->vambraces);
}

void NPC::equipAll(){
	for (unsigned int i = 0; i < backpack->inventory.size(); i++){
		backpack->inventory[i]->equip(this);
	}
	updateProts();
}

Goblin::Goblin(Map* m) : NPC(){
	name = "Goblin";
	character = 'g';
	racialAlignment = monster;
	backpack->inventory.clear();
	backpack->inventory.push_back(new Shortsword(backpack));
	equipAll();
	stats->setHP(50);
	stats->setStam(50);
	stats->setMana(50);
	stats->setStr(15);
	stats->setVit(15);
	stats->setDex(15);
	stats->setQuick(15);
	stats->setIntel(10);
	stats->setWis(10);
	ai = new MeleeAI(m, this);

}

Goblin::~Goblin(){

}