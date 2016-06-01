#ifndef GRAVESTONE_H
#define GRAVESTONE_H

#include "Armor.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Character.h"

class Gravestone{
public:
	

	Gravestone(Character* c);
	~Gravestone();

	bool lootGrave(Character* c);

	int getXpos(){ return posX; }
	int getYpos(){ return posY; }

	Symbol* getMarker(){ return marker; }

private:
	string name;
	Inventory *grave;
	int posX, posY;
	Symbol* marker;

};

#endif