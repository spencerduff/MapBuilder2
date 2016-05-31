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
string Item::equip(Character *c){
	return "";
}

string Item::examine(){
	stringstream ss;
	ss << name << endl;
	ss << symbol << endl;
	ss << "Weight: " << setprecision(2) << fixed << weight << endl;
	return ss.str();
}

void Item::enchant(Enchant* e){
	return;
}

void Item::addToEnchantingTable(Thaumaturgy *t){
	cout << "Not an item to use here. " << endl;
}