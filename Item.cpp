#include "Item.h"
#include "Character.h"

unsigned long Item::nextID = 0;

Item::Item(){
	nextID++;
}

Item::~Item(){

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