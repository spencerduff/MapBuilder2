#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Character;

enum Piece { helm, chest, legs, greaves, gauntlets, elbows, boots, vambraces, girdle, shoulders, necklace, ring, earring, robe, shield };

class Armor : public Item{
public:
	Piece piece;
	void equip(Character *c) override;

protected:
	float encumberance;
	float dura;
	float duraMax;
	float protBludgeoning, protSlashing, protPiercing, protAcid, protCold, protFire, protHoly, protLightning, protUnholy, protImpact;

};

#endif