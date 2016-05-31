#include "Gravestone.h"

Gravestone::Gravestone(Character *c){
	posX = c->getXpos();
	posY = c->getYpos();
	grave = c->getBackpack();
	stringstream ss;
	ss << "Here lies " << c->getName() << ".";
	name = ss.str();
}

Gravestone::~Gravestone(){
	delete grave;
	grave = NULL;
}

bool Gravestone::lootGrave(Character* c){
	cout << name << endl;
	cout << grave->printInv();
	cout << "Press Q to not loot gear." << endl;
	char input = _getch();
	int pos = grave->parsePosInBackpack(input);
	if (pos < grave->inventory.size()){
		c->getBackpack()->inventory.push_back(grave->inventory[pos]->clone());
		c->getBackpack()->inventory.back()->setParentContainer(c->getBackpack());
		swap(grave->inventory[pos], grave->inventory.back());
		grave->inventory.pop_back();
		if (grave->inventory.empty()){
			delete this;
			return true;
		}
	}
	return false;
}