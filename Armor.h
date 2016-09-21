#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"

class Character;

// What slot of the paperdoll it will go into
enum Piece { helm, chest, legs, greaves, gauntlets, elbows, boots, vambraces, girdle, shoulders, necklace, ring, earring, robe, shield };

// All the protections armor can have
struct Prots{
	float protBludgeoning, protSlashing, protPiercing, protAcid, protCold, protFire, protHoly, protLightning, protUnholy, protImpact, protArcane;
};

// Armor that can be inherited from. It has functions for equipping it (AI or not), crafting it, using it, etc...
class Armor : public Item{
public:
	// Armor has to know his parent container upon creation, so it can be used in the deletion of the armor
	// Passed up to Item's constructor
	Armor(Inventory* p);
	// Virtual destructors to destroy what's needed when the parent classes are called
	virtual ~Armor();
	// Used with clone in looting. Needed because of the use of vectors
	Armor(const Armor& rhs);

	Item* clone() override;

	// Some setters
	void setName(string newName){ Item::setName(newName); }
	void setSymbol(Symbol* newSymbol){ Item::setSymbol(newSymbol); }
	void setWeight(float newWeight){ Item::setWeight(newWeight); }

	void use(Character* c) override { equip(c); }
	// Overridden function of Item to equip an item to its correct slot on the paperdoll of a passed in Character*
	void equip(Character *c) override;
	// Overridden function of Item that prints out details about the armor
	void examine() override;
	// Decrements durability. Need to implement a check for deletion.
	void decrementDura(){ this->dura -= float(.10); }

	// Overridden function of Item that adds the armor to the correct spot on the enchanting table.
	void addToEnchantingTable(Thaumaturgy *t) override;

	// Getters
	Prots getProts(){ return prots; }
	float getEncumbrance(){ return encumbrance; }
	float getDura(){ return dura; }
	Piece getPiece(){ return piece; }


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