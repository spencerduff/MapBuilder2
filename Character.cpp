#include "Character.h"


Character::Character(){
	character = '@';
	movement = NULL;
	xPos = NULL;
	yPos = NULL;
	backpack = new Inventory;
	paperdoll = new Paperdoll;
	backpack->inventory.push_back(new Leafblade());
	backpack->inventory.push_back(new DragonChest());
}

Character::Character(int x, int y){
	character = '@';
	movement = NULL;
	xPos = x;
	yPos = y;

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

void Character::equip(Item *equippable){
	// Check to see if it's in the characters backpack
	for (int i = 0; i < backpack->inventory.size(); i++){
		if (equippable->itemID = backpack->inventory[i]->itemID){
			equippable->equip(this);
			break;
		}

	}

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
		equip(temp);
	}
}