#include "Item.h"

unsigned long Item::nextID = 0;

Item::Item(){
	nextID++;
}