#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item{
public:
	static unsigned long nextID;
	string name;
	char symbol;
	float weight;
	unsigned long itemID;
	Item();

protected:

};

#endif