#include "Item.h"
#include "Character.h"

unsigned long Item::nextID = 0;

Item::Item(){
	nextID++;
}

Item::~Item(){

}

//Add functionality for bags, runestones, food, pots, etc...
void Item::equip(Character *c){
	return;
}

void Item::examine(){
	cout << name << endl;
	cout << symbol << endl;
	cout << "Weight: " << endl;

}