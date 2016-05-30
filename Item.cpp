#include "Item.h"
#include "Character.h"

unsigned long Item::nextID = 0;

Item::Item(){
	nextID++;
}

Item::~Item(){

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
	ss << "Weight: " << endl;
	return ss.str();
}