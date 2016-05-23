#ifndef CHARACTER_H
#define CHARACTER_H


#include <Windows.h>
#include <conio.h>
#include "Inventory.h"
#include "CharacterStats.h"

class Item;

class Character{
public:
	Character();
	Character(int x, int y);
	void setPos(int x, int y);
	char getChar();
	void moveChar(char m = NULL);
	char getMovement();
	int getXpos();
	int getYpos();
	void equip(Item *equippable);
	Paperdoll* getPaperdoll(){ return paperdoll; }

private:
	int xPos, yPos;
	char movement;
	char character;
	Inventory *backpack;
	Paperdoll *paperdoll;
	bool isMovement(char m);
	void examineItem();
	CharacterStats *stats;
	void putOnGear();
	void updateProts();

};



#endif // !CHARACTER_H