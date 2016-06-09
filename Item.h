#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <sstream>

#include "Symbol.h"

using namespace std;

class Character;
class Enchant;
class Thaumaturgy;
class Inventory;

// Items are held by Characters in their backpacks. Also on Gravestones. Items are lootable and useable.
class Item{
public:
	virtual ~Item();
	Item(const Item &obj);
	// Used when copying over Items from looting a Gravestone. Needed for how the copying works with Vectors which hold the Items.
	virtual Item* clone(){ return new Item(*this); }

	bool equipped;

	// Overridden function to equip an item to a Character. Will be used for using Items that aren't equippable as well.
	virtual void equip(Character *c);
	// Overridden function to examine the attributes of an Item. Prints to the screen.
	virtual void examine();
	// Adds stackable Items together. Overridden because subclasses determine if they are stackable or not.
	virtual void addStacks(Item* i);
	// Getter. Overridden because subclasses determine if they are stackable or not.
	virtual int getStack();

	virtual void use(Character* c);

	// Overridden to enchant an Item. Will call correct Weapon/Armor/Staff enchant through polymorphism.
	virtual void enchant(Enchant* e);

	// Add an Item to the enchanting table. Used for Weapon/Armor/Staff.
	virtual void addToEnchantingTable(Thaumaturgy *t);

	// Getters.
	unsigned long getNextID(){ return nextID; }
	Symbol* getSymbol(){ return symbol; }
	string getName(){ return name; }
	float getWeight(){ return weight; }
	unsigned long getItemID(){ return itemID; }
	bool isStackable(){ return stackable; }

	// Item needs to know its parent container for when it is deleted.
	void setParentContainer(Inventory* p){ parent = p; }

protected:
	Item(Inventory* p);
	bool stackable;
	bool useable;
	Inventory* parent;

	void setName(string newName){ name = newName; }
	void setSymbol(Symbol* newSymbol){ symbol = newSymbol; }
	void setWeight(float newWeight){ weight = newWeight; }
	void setItemID(unsigned long newID){ itemID = newID; }

private:
	static unsigned long nextID;
	string name;
	Symbol* symbol;
	float weight;
	unsigned long itemID;

};

#endif