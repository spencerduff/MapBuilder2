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

void Inventory::printInv(){
	for (int i = 0; i < inventory.size() && i < 36; i++){
		cout << inventory[i]->getSymbol() << " " << inventory[i]->getName() << " " << invSpace[i];
		if (inventory[i]->equipped)
			cout << " *EQUIPPED*";
		cout << endl;
	}
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

void Paperdoll::printPaperdoll(){
	cout << "    ";
	if (earring != NULL)
		cout << "[" << earring->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (helm != NULL)
		cout << "[" << helm->getSymbol() << "]";
	else cout << "[ ]";
	cout << endl;
	cout << "      ";
	if (necklace != NULL)
		cout << "[" << necklace->getSymbol() << "]";
	else cout << "[ ]";
	cout << endl;
	
	cout << "  ";
	if (robe != NULL)
		cout << "[" << robe->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (chest != NULL)
		cout << "[" << chest->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (shoulders != NULL)
		cout << "[" << shoulders->getSymbol() << "]";
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	if (vambraces != NULL)
		cout << "[" << vambraces->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (legs != NULL)
		cout << "[" << legs->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (elbows != NULL)
		cout << "[" << elbows->getSymbol() << "]";
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	cout << "  ";
	if (girdle != NULL)
		cout << "[" << girdle->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (gauntlets != NULL)
		cout << "[" << gauntlets->getSymbol() << "]";
	else cout << "[ ]";
	cout << endl;

	if (lhRing != NULL)
		cout << "[" << lhRing->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (greaves != NULL)
		cout << "[" << greaves->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (boots != NULL)
		cout << "[" << boots->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (rhRing != NULL)
		cout << "[" << rhRing->getSymbol() << "]";
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	if (primary != NULL)
		cout << "[" << primary->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (shield != NULL)
		cout << "[" << shield->getSymbol() << "]";
	else cout << "[ ]";
	cout << " ";
	if (quiver != NULL)
		cout << "[" << quiver->getSymbol() << "]";
	else cout << "[ ]";
	cout << endl;
}

