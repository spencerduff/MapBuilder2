#ifndef GRAVESTONE_H
#define GRAVESTONE_H

#include "Armor.h"
#include "Weapon.h"
#include "Inventory.h"
#include "Character.h"

// Gravestones are created upon the death of a Character to hold their loot.
class Gravestone{
public:
	// Creates a Gravestone from a Character's death
	Gravestone(Character* c);
	~Gravestone();

	// Loot a grave. Returns true if the grave is empty or false if there are things left in it
	bool lootGrave(Character* c);

	// Getters
	int getXpos(){ return posX; }
	int getYpos(){ return posY; }
	Symbol* getMarker(){ return marker; }
	Inventory* getGrave(){ return grave; }

private:
	string name;
	Inventory *grave;
	int posX, posY;
	Symbol* marker;

};

#endif