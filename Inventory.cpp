#include "Inventory.h"

char invSpace[]= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

Inventory::Inventory(){

}

Inventory::~Inventory(){
	for (auto i = inventory.begin(); i < inventory.end(); ++i){
		delete *i;
		*i = NULL;
	}
	inventory.clear();
}

string Inventory::printInv(){
	stringstream ss;
	for (int i = 0; i < inventory.size() && i < 36; i++){
		ss << inventory[i]->getSymbol() << " " << inventory[i]->getName() << " " << invSpace[i];
		if (inventory[i]->equipped)
			ss << " *EQUIPPED*";
		ss << endl;
	}
	return ss.str();
}

Paperdoll::Paperdoll(){
	helm = NULL;
	chest = NULL;
	legs = NULL;
	greaves = NULL;
	gauntlets = NULL;
	elbows = NULL;
	boots = NULL;
	vambraces = NULL;
	girdle = NULL;
	shoulders = NULL;
	necklace = NULL;
	rhRing = NULL;
	lhRing = NULL;
	earring = NULL;
	robe = NULL;
	shield = NULL;
	primary = NULL;
	quiver = NULL;
}

Paperdoll::~Paperdoll(){
	delete helm;
	delete chest;
	delete legs;
	delete greaves;
	delete gauntlets;
	delete elbows;
	delete boots;
	delete vambraces;
	delete girdle;
	delete shoulders;
	delete necklace;
	delete rhRing;
	delete lhRing;
	delete earring;
	delete robe;
	delete shield;
	delete primary;
	delete quiver;
	
	helm = chest = legs = greaves = gauntlets = elbows = boots = vambraces = girdle = shoulders = necklace = rhRing = lhRing = earring = robe = shield = NULL;
	primary = quiver = NULL;
}

void Paperdoll::unequip(Item *a){
	if (a != NULL)
		a->equipped = false;
}

string Paperdoll::printPaperdoll(){
	stringstream ss;
	ss << "    ";
	if (earring != NULL)
		ss << "[" << earring->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (helm != NULL)
		ss << "[" << helm->getSymbol() << "]";
	else ss << "[ ]";
	ss << endl;
	ss << "      ";
	if (necklace != NULL)
		ss << "[" << necklace->getSymbol() << "]";
	else ss << "[ ]";
	ss << endl;
	
	ss << "  ";
	if (robe != NULL)
		ss << "[" << robe->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (chest != NULL)
		ss << "[" << chest->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (shoulders != NULL)
		ss << "[" << shoulders->getSymbol() << "]";
	else ss << "[ ]";
	ss << endl;

	ss << "  ";
	if (vambraces != NULL)
		ss << "[" << vambraces->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (legs != NULL)
		ss << "[" << legs->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (elbows != NULL)
		ss << "[" << elbows->getSymbol() << "]";
	else ss << "[ ]";
	ss << endl;

	ss << "  ";
	ss << "  ";
	if (girdle != NULL)
		ss << "[" << girdle->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (gauntlets != NULL)
		ss << "[" << gauntlets->getSymbol() << "]";
	else ss << "[ ]";
	ss << endl;

	if (lhRing != NULL)
		ss << "[" << lhRing->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (greaves != NULL)
		ss << "[" << greaves->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (boots != NULL)
		ss << "[" << boots->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (rhRing != NULL)
		ss << "[" << rhRing->getSymbol() << "]";
	else ss << "[ ]";
	ss << endl;

	ss << "  ";
	if (primary != NULL)
		ss << "[" << primary->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (shield != NULL)
		ss << "[" << shield->getSymbol() << "]";
	else ss << "[ ]";
	ss << " ";
	if (quiver != NULL)
		ss << "[" << quiver->getSymbol() << "]";
	else ss << "[ ]";
	ss << endl;

	return ss.str();
}
