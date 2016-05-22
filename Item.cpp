#include "Item.h"
#include "Character.h"

unsigned long Item::nextID = 0;

Item::Item(){
	nextID++;
}

//Add functionality for bags, runestones, food, pots, etc...
void Item::equip(Character *c){
	return;
}