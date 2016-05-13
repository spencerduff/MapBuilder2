#include "Character.h"


Character::Character(){
	character = '@';
	movement = NULL;
	xPos = NULL;
	yPos = NULL;
	inv.inventory.push_back(Leafblade());
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
