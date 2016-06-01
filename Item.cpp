#include "Item.h"
#include "Character.h"
#include <iomanip>

unsigned long Item::nextID = 0;

Item::Item(Inventory* p){
	stackable = false;
	equipped = false;
	nextID++;
	parent = p;
}

Item::~Item(){
	parent->removeItem(this);
}

Item::Item(const Item &obj){
	this->equipped = obj.equipped;
	this->name = obj.name;
	this->symbol = obj.symbol;
	this->weight = obj.weight;
	this->itemID = obj.itemID;
}

//Add functionality for bags, runestones, food, pots, etc...
void Item::equip(Character *c){
	return;
}

void Item::examine(){
	cout << name << endl;
	symbol->printSymbol();
	cout << endl;
	cout << "Weight: " << setprecision(2) << fixed << weight << endl;
}

void Item::enchant(Enchant* e){
	return;
}

void Item::addToEnchantingTable(Thaumaturgy *t){
	cout << "Not an item to use here. " << endl;
}