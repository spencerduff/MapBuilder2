#include "Character.h"


Character::Character(){
	character = '@';
	movement = NULL;
	xPos = NULL;
	yPos = NULL;
	backpack.inventory.push_back(Leafblade());
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
		paperdoll.printPaperdoll();
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

void Character::equipArmor(Armor *equippable){
	// Check to see if it's in the characters backpack
	for (int i = 0; i < backpack.inventory.size(); i++){
		if (equippable->itemID = backpack.inventory[i].itemID){
			switch (equippable->piece) {
			case helm: paperdoll.helm = equippable;
				break;
			case chest: paperdoll.chest = equippable;
				break;
			case legs: paperdoll.legs = equippable;
				break;
			case greaves: paperdoll.greaves = equippable;
				break;
			case gauntlets: paperdoll.gauntlets = equippable;
				break;
			case elbows: paperdoll.elbows = equippable;
				break;
			case boots: paperdoll.boots = equippable;
				break;
			case vambraces: paperdoll.vambraces = equippable;
				break;
			case girdle: paperdoll.girdle = equippable;
				break;
			case shoulders: paperdoll.shoulders = equippable;
				break;
			case necklace: paperdoll.necklace = equippable;
				break;
			case ring: 
				if (paperdoll.rhRing != NULL)
					paperdoll.lhRing = equippable;
				else
					paperdoll.rhRing = equippable;
				break;
			case earring: paperdoll.earring = equippable;
				break;
			case robe: paperdoll.robe = equippable;
				paperdoll.helm = NULL;
				paperdoll.chest = NULL;
				paperdoll.legs = NULL;
				paperdoll.greaves = NULL;
				paperdoll.gauntlets = NULL;
				paperdoll.elbows = NULL;
				paperdoll.boots = NULL;
				paperdoll.vambraces = NULL;
				paperdoll.girdle = NULL;
				paperdoll.shoulders = NULL;
				break;
			case shield: paperdoll.shield = equippable;
				break;
			}
		}

	}

}

void Character::equipWeapon(Weapon *equippable){



}