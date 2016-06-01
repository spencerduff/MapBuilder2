#include "Character.h"


Character::Character(){
	character = new Symbol('@', NULL, NULL, 6);
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
	name = "Zorak Warslayer";
	movement = NULL;
	xPos = x;
	yPos = y;
	character = new Symbol('@', x, y, 6);
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

Symbol* Character::getChar(){
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
		clearPastMap();
	}
	else if (m == 'p')
		paperdoll->printPaperdoll();
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
	else if (m == 'f')
		movement = m;
	else movement = NULL;
}

void Character::clearPastMap(){
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 52 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
		)) return;
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

void Character::equip(Item *equippable, bool &result){
	// Check to see if it's in the characters backpack
	for (unsigned int i = 0; i < backpack->inventory.size(); i++){
		if (equippable->getItemID() == backpack->inventory[i]->getItemID()){
			if (equippable->equipped){
				cout << equippable->getName() << " is already equipped." << endl;
				result = false;
				return;
			}
			else{
				equippable->equip(this);
				result = true;
				return;
			}
		}

	}
	result = false;
}

void Character::examineItem(){
	backpack->printInv();
	cout << "Which item would you like to examine? Q to not examine any. " << endl << endl;
	char input = _getch();
	if (input == 'Q') return;
	int pos = backpack->parsePosInBackpack(input);
	if (pos < backpack->inventory.size()){
		Item *temp = backpack->inventory[pos];
		temp->examine();
	}
}

void Character::putOnGear(){
	backpack->printInv();
	cout << "Press Q to not put on gear." << endl;
	char input = _getch();
	int pos = backpack->parsePosInBackpack(input);
	if (pos < backpack->inventory.size()){
		Item *temp = backpack->inventory[pos];
		bool result = false;
		equip(temp, result);
		if(result)
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
//Will be more complex once weapon skills/masteries/pacoutives and such.
void Character::calculateMeleeDamage(Character* c){
	if (this->paperdoll->primary == NULL){
		cout << "There's no weapon to attack with! " << endl;
		return;
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
	
	c->damage(incDamage);

	cout << this->paperdoll->primary->decrementDura();
	bool delPrim = true;
	for (unsigned int i = 0; i < backpack->inventory.size(); i++){
		if (backpack->inventory[i] == paperdoll->primary)
			delPrim = false;
	}
	if (delPrim)
		paperdoll->primary = NULL;
}

void Character::damage(Damage incDamage){
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
	cout << this->name << "'s HP is now: " << this->stats->getHP() << " after " << incDamage.numOfHits;
	if (incDamage.numOfHits == 1)
		cout << " hit." << endl;
	else
		cout << " hits." << endl;
}

void Character::putCursorPastMap(){
	COORD homeCoords = { 0, 52 };
	HANDLE hStdOut= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, homeCoords);
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

void Character::tryDeleteArmor(){
	if (paperdoll->helm != NULL)
		if (paperdoll->helm->getDura() <= 0){
			delete paperdoll->helm;
			paperdoll->helm = NULL;
		}
	if (paperdoll->chest != NULL)
		if (paperdoll->chest->getDura() <= 0){
			delete paperdoll->chest;
			paperdoll->chest = NULL;
		}
	if (paperdoll->boots != NULL)
		if (paperdoll->boots->getDura() <= 0){
			delete paperdoll->boots;
			paperdoll->boots = NULL;
		}
	if (paperdoll->earring != NULL)
		if (paperdoll->earring->getDura() <= 0){
			delete paperdoll->earring;
			paperdoll->earring = NULL;
		}
	if (paperdoll->elbows != NULL)
		if (paperdoll->elbows->getDura() <= 0){
			delete paperdoll->elbows;
			paperdoll->elbows = NULL;
		}
	if (paperdoll->gauntlets != NULL)
		if (paperdoll->gauntlets->getDura() <= 0){
			delete paperdoll->gauntlets;
			paperdoll->gauntlets = NULL;
		}
	if (paperdoll->girdle != NULL)
		if (paperdoll->girdle->getDura() <= 0){
			delete paperdoll->girdle;
			paperdoll->girdle = NULL;
		}
	if (paperdoll->greaves != NULL)
		if (paperdoll->greaves->getDura() <= 0){
			delete paperdoll->greaves;
			paperdoll->greaves = NULL;
		}
	if (paperdoll->legs != NULL)
		if (paperdoll->legs->getDura() <= 0){
			delete paperdoll->legs;
			paperdoll->legs = NULL;
		}
	if (paperdoll->lhRing != NULL)
		if (paperdoll->lhRing->getDura() <= 0){
			delete paperdoll->lhRing;
			paperdoll->lhRing = NULL;
		}
	if (paperdoll->necklace != NULL)
		if (paperdoll->necklace->getDura() <= 0){
			delete paperdoll->necklace;
			paperdoll->necklace = NULL;
		}
	if (paperdoll->rhRing != NULL)
		if (paperdoll->rhRing->getDura() <= 0){
			delete paperdoll->rhRing;
			paperdoll->rhRing = NULL;
		}
	if (paperdoll->robe != NULL)
		if (paperdoll->robe->getDura() <= 0){
			delete paperdoll->robe;
			paperdoll->robe = NULL;
		}
	if (paperdoll->shield != NULL)
		if (paperdoll->shield->getDura() <= 0){
			delete paperdoll->shield;
			paperdoll->shield = NULL;
		}
	if (paperdoll->shoulders != NULL)
		if (paperdoll->shoulders->getDura() <= 0){
			delete paperdoll->shoulders;
			paperdoll->shoulders = NULL;
		}
	if (paperdoll->vambraces != NULL)
		if (paperdoll->vambraces->getDura() <= 0){
			delete paperdoll->vambraces;
			paperdoll->vambraces = NULL;
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
	character = new Symbol('g', NULL, NULL, 2);
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