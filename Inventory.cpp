#include "Inventory.h"

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

