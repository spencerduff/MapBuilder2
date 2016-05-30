#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <sstream>

using namespace std;

class Character;



class Item{
public:
	Item();
	virtual ~Item();
	Item(const Item &obj);

	virtual Item* clone(){ return new Item(*this); }

	bool equipped;

	virtual string equip(Character *c);
	virtual string examine();

	unsigned long getNextID(){ return nextID; }
	char getSymbol(){ return symbol; }
	string getName(){ return name; }
	float getWeight(){ return weight; }
	unsigned long getItemID(){ return itemID; }

protected:
	void setName(string newName){ name = newName; }
	void setSymbol(char newSymbol){ symbol = newSymbol; }
	void setWeight(float newWeight){ weight = newWeight; }
	void setItemID(unsigned long newID){ itemID = newID; }

private:
	static unsigned long nextID;
	string name;
	char symbol;
	float weight;
	unsigned long itemID;

};

#endif