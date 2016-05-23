#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Character;



class Item{
public:
	static unsigned long nextID;
	string name;
	char symbol;
	float weight;
	bool equipped;
	unsigned long itemID;
	Item();

	virtual void equip(Character *c);
	virtual void examine();


protected:

};

#endif