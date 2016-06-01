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

class Item{
public:
	virtual ~Item();
	Item(const Item &obj);

	virtual Item* clone(){ return new Item(*this); }

	bool equipped;

	virtual void equip(Character *c);
	virtual void examine();


	virtual void enchant(Enchant* e);

	virtual void addToEnchantingTable(Thaumaturgy *t);

	unsigned long getNextID(){ return nextID; }
	Symbol* getSymbol(){ return symbol; }
	string getName(){ return name; }
	float getWeight(){ return weight; }
	unsigned long getItemID(){ return itemID; }

	void setParentContainer(Inventory* p){ parent = p; }

protected:
	Item(Inventory* p);
	bool stackable;
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