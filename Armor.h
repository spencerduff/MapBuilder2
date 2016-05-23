#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Character;

enum Piece { helm, chest, legs, greaves, gauntlets, elbows, boots, vambraces, girdle, shoulders, necklace, ring, earring, robe, shield };

struct Prots{
	float protBludgeoning, protSlashing, protPiercing, protAcid, protCold, protFire, protHoly, protLightning, protUnholy, protImpact, protArcane;
};

class Armor : public Item{
public:
	void setName(string newName){ name = newName; }
	void setSymbol(char newSymbol){ symbol = newSymbol; }
	void setWeight(float newWeight){ weight = newWeight; }
	Piece piece;
	Armor();
	void equip(Character *c) override;
	void examine() override;
	Prots getProts(){ return prots; }
	float getEncumberance(){ return encumberance; }

protected:
	string maker;
	float encumberance;
	float dura;
	float duraMax;
	Prots prots;
};

class DragonChest : public Armor{
public:
	DragonChest();

private:
	void setNameOfWep(string name){ setName(name); }
	void setSymbolOfWep(char symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }

};



#endif