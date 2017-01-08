#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Crafting.h"
#include "Character.h"

using namespace std;

void CraftingStation::setPos(int x, int y){
	posX = x;
	posY = y;
}

CraftingStation::~CraftingStation(){
	delete symbol;
	symbol = nullptr;
}

Thaumaturgy::Thaumaturgy(){
	name = "Thaumaturgist's Table";
	symbol = new Symbol('%', 14, BACKGROUND_GREEN | BACKGROUND_RED);
	posX = NULL;
	posY = NULL;

	enchants.push_back(new Keen());
}

Thaumaturgy::~Thaumaturgy(){
	for (auto it = enchants.begin(); it != enchants.end(); ++it){
		delete (*it);
		*it = nullptr;
	}
	enchants.clear();
}

void Thaumaturgy::setCatalyst(EnchantingCatalyst* i){
	cat = i;
}

void Thaumaturgy::setEnchantMat(EnchantingMat* i){
	if (mat1 == NULL)
		mat1 = i;
	else if (mat2 == NULL)
		mat2 = i;
	else if (mat3 == NULL)
		mat3 = i;
}

void Thaumaturgy::printEnchantingScreen(){
	cout << name << endl << endl;
	cout << "The Thaumaturgist's Table's contents: " << endl;
	cout << "Materials..." << endl;
	cout << "[ ";
	if (mat1 != NULL)
		cout << mat1->getName();
	cout << " ] " << "[ ";
	if (mat2 != NULL)
		cout << mat2->getName();
	cout << " ] " << "[ ";
	if (mat3 != NULL)
		cout << mat3->getName();
	cout << " ]" << endl;
	cout << "Catalyst..." << endl;
	cout << "[ ";
	if (cat != NULL)
		cout << cat->getName();
	cout << " ]" << endl;
	cout << "Item to enchant..." << endl; 
	cout << "[ ";
	if (toEnchant != NULL)
		cout << toEnchant->getName();
	cout << " ]" << endl << endl;
	
	cout << "C to remove catalyst, M to remove mats, and I to remove item to enchant." << endl;
	cout << "E to enchant." << endl;
	cout << "Which items would you like to add? Q to quit." << endl << endl;
}

void Thaumaturgy::craft(Character* c){
	COORD posReturn = { 0, 52 };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	bool failFlag = false;
	while (true){
		SetConsoleCursorPosition(output, posReturn);
		c->clearPastMap();
		printEnchantingScreen();
		c->getBackpack()->printInv();
		if (failFlag){
			cout << "Add more to the enchanting table to start an enchant." << endl;
			failFlag = false;
		}
		char input = _getch();
		if (input == 'Q'){
			this->mat1 = NULL;
			this->mat2 = NULL;
			this->mat3 = NULL;
			this->cat = NULL;
			this->toEnchant = NULL;
			return;
		}
		if (input == 'C'){
			this->cat = NULL;
			continue;
		}
		if (input == 'M'){
			this->mat1 = NULL;
			this->mat2 = NULL;
			this->mat3 = NULL;
			continue;
		}
		if (input == 'I'){
			this->toEnchant = NULL;
			continue;
		}
		if (input == 'E'){
			if (this->mat1 == NULL || this->mat2 == NULL || this->mat3 == NULL || this->cat == NULL || this->toEnchant == NULL){
				failFlag = true;
				continue;
			}
			else {
				enchant(this->mat1, this->mat2, this->mat3, this->cat, this->toEnchant);
				this->mat1->decrementStack();
				this->mat2->decrementStack();
				this->mat3->decrementStack();
				this->cat->decrementStack();
				this->mat1 = NULL;
				this->mat2 = NULL;
				this->mat3 = NULL;
				this->cat = NULL;
				this->toEnchant = NULL;				
				return;
			}
		}
		unsigned int pos = c->getBackpack()->parsePosInBackpack(input);
		if (pos < c->getBackpack()->inventory.size()){
			Item *temp = c->getBackpack()->inventory[pos];
			temp->addToEnchantingTable(this);
		}
	}
}

// I want to start with a list of every enchant. Then by process of elimination, add enchanting mats until only one enchant remains.
// Then attempt to apply that enchant to the item.
void Thaumaturgy::enchant(EnchantingMat* m1, EnchantingMat* m2, EnchantingMat* m3, EnchantingCatalyst* c, Item* i){
	vector<Enchant*> possibleEnchants = enchants;
	for (unsigned int j = 0; j < possibleEnchants.size(); j++){
		if (possibleEnchants[j]->getReq1() != m1->getMat() && possibleEnchants[j]->getReq2() != m1->getMat() && possibleEnchants[j]->getReq3() != m1->getMat()){
			possibleEnchants.erase(possibleEnchants.begin() + j);
			j--;
			continue;
		}
		if (possibleEnchants[j]->getReq1() != m2->getMat() && possibleEnchants[j]->getReq2() != m2->getMat() && possibleEnchants[j]->getReq3() != m2->getMat()){
			possibleEnchants.erase(possibleEnchants.begin() + j);
			j--;
			continue;
		}
		if (possibleEnchants[j]->getReq1() != m3->getMat() && possibleEnchants[j]->getReq2() != m3->getMat() && possibleEnchants[j]->getReq3() != m3->getMat()){
			possibleEnchants.erase(possibleEnchants.begin() + j);
			j--;
			continue;
		}
		if (possibleEnchants[j]->getCata() != c->getCatalyst()){
			possibleEnchants.erase(possibleEnchants.begin() + j);
			j--;
			continue;
		}
	}

	if (!possibleEnchants.empty()){
		possibleEnchants[0]->enchant(m1, m2, m3, c, i);
	}


}