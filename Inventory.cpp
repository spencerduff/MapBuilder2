#include "Inventory.h"

char invSpace[]= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

Inventory::Inventory(){

}

void Inventory::printInv(){
	for (int i = 0; i < inventory.size() && i < 36; i++){
		cout << inventory[i]->symbol << " " << inventory[i]->name << " " << invSpace[i];
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

void Paperdoll::unequip(Item *a){
	if (a != NULL)
		a->equipped = false;
}

void Paperdoll::printPaperdoll(){
	cout << "    ";
	if (earring != NULL)
		cout << "[" << earring->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (helm != NULL)
		cout << "[" << helm->symbol << "]";
	else cout << "[ ]";
	cout << endl;
	cout << "      ";
	if (necklace != NULL)
		cout << "[" << necklace->symbol << "]";
	else cout << "[ ]";
	cout << endl;
	
	cout << "  ";
	if (robe != NULL)
		cout << "[" << robe->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (chest != NULL)
		cout << "[" << chest->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (shoulders != NULL)
		cout << "[" << shoulders->symbol << "]";
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	if (vambraces != NULL)
		cout << "[" << vambraces->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (legs != NULL)
		cout << "[" << legs->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (elbows != NULL)
		cout << "[" << elbows->symbol << "]";
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	cout << "  ";
	if (girdle != NULL)
		cout << "[" << girdle->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (gauntlets != NULL)
		cout << "[" << gauntlets->symbol << "]";
	else cout << "[ ]";
	cout << endl;

	if (lhRing != NULL)
		cout << "[" << lhRing->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (greaves != NULL)
		cout << "[" << greaves->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (boots != NULL)
		cout << "[" << boots->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (rhRing != NULL)
		cout << "[" << rhRing->symbol << "]";
	else cout << "[ ]";
	cout << endl;

	cout << "  ";
	if (primary != NULL)
		cout << "[" << primary->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (shield != NULL)
		cout << "[" << shield->symbol << "]";
	else cout << "[ ]";
	cout << " ";
	if (quiver != NULL)
		cout << "[" << quiver->symbol << "]";
	else cout << "[ ]";
	cout << endl;
}

