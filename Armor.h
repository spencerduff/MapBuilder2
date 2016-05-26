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
	Armor();
	virtual ~Armor();
	void setName(string newName){ Item::setName(newName); }
	void setSymbol(char newSymbol){ Item::setSymbol(newSymbol); }
	void setWeight(float newWeight){ Item::setWeight(newWeight); }
	string equip(Character *c) override;
	string examine() override;
	Prots getProts(){ return prots; }
	float getEncumbrance(){ return encumbrance; }


protected:
	string maker;
	float encumbrance;
	float dura;
	float duraMax;
	Prots prots;
	Piece piece;
};

class DragonChest : public Armor{
public:
	DragonChest();
	~DragonChest();

private:
	void setNameOfWep(string name){ setName(name); }
	void setSymbolOfWep(char symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }

};



#endif