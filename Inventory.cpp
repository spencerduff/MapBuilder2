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
	for (unsigned int i = 0; i < inventory.size() && i < 36; i++){
		inventory[i]->getSymbol()->printSymbol();
		if (inventory[i]->isStackable())
			cout << " (" << inventory[i]->getStack() << ")";
		cout << " " << inventory[i]->getName() << " " << invSpace[i];
		if (inventory[i]->equipped)
			cout << " *EQUIPPED*";
		cout << endl;
	}
}

int Inventory::parsePosInBackpack(char input){
	if (input == 'Q') return -1;
	int pos = 0;
	if (input >= 97 && input <= 122)
		pos = (input - 87);
	else if (input >= 48 && input <= 57)
		pos = (input - 48);
	else return -1;
	return pos;
}

void Inventory::removeItem(Item* item){
	for (unsigned int i = 0; i < inventory.size(); i++){
		if (inventory[i]->getItemID() == item->getItemID()){
			inventory.erase(inventory.begin() + i);
		}
	}
}

void Inventory::consolidateStackables(){
	for (unsigned int i = 0; i < inventory.size(); i++){
		if (inventory[i]->isStackable()){
			for (unsigned int j = i + 1; j < inventory.size(); j++){
				if (inventory[j]->getName() == inventory[i]->getName()){
					inventory[i]->addStacks(inventory[j]);
				}
			}
		}
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
	if (earring != NULL){
		cout << "["; 
		earring->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (helm != NULL){
		cout << "[";
		helm->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << endl;
	cout << "      ";
	if (necklace != NULL){
		cout << "[";
		necklace->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << endl;
	
	cout << "  ";
	if (robe != NULL){
		cout << "[";
		robe->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (chest != NULL){
		cout << "[";
		chest->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (shoulders != NULL){
		cout << "[";
		shoulders->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	if (vambraces != NULL){
		cout << "[";
		vambraces->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (legs != NULL){
		cout << "[";
		legs->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (elbows != NULL){
		cout << "[";
		elbows->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	cout << "  ";
	if (girdle != NULL){
		cout << "[";
		girdle->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (gauntlets != NULL){
		cout << "[";
		gauntlets->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << endl;

	if (lhRing != NULL){
		cout << "[";
		lhRing->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (greaves != NULL){
		cout << "[";
		greaves->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (boots != NULL){
		cout << "[";
		boots->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (rhRing != NULL){
		cout << "[";
		rhRing->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	if (primary != NULL){
		cout << "[";
		primary->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (shield != NULL){
		cout << "[";
		shield->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << " ";
	if (quiver != NULL){
		cout << "[";
		quiver->getSymbol()->printSymbol();
		cout << "]";
	}
	else cout << "[ ]";
	cout << endl;

}
