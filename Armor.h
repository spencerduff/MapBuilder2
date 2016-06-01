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
	Armor(Inventory* p);
	virtual ~Armor();
	Armor(const Armor& rhs);

	Item* clone() override;

	void setName(string newName){ Item::setName(newName); }
	void setSymbol(Symbol* newSymbol){ Item::setSymbol(newSymbol); }
	void setWeight(float newWeight){ Item::setWeight(newWeight); }

	void equip(Character *c) override;
	void examine() override;
	void decrementDura(){ this->dura -= .10; }

	void addToEnchantingTable(Thaumaturgy *t) override;

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
	DragonChest(Inventory* p);
	~DragonChest();

private:
	void setNameOfWep(string name){ setName(name); }
	void setSymbolOfWep(Symbol* symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }

};



#endif