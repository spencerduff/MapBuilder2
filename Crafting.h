#ifndef CRAFTING_H
#define CRAFTING_H

#include "Enchants.h"
#include <vector>

// Parent class for crafting stations. Every crafting station has functions from this class.
class CraftingStation{
public:
	// Set the position on the map of the crafting station
	void setPos(int x, int y);

	virtual ~CraftingStation();

	// Getters
	int getXpos(){ return posX; }
	int getYpos(){ return posY; }
	Symbol* getChar(){ return symbol; }

	// Craft function. Subclasses determine how they craft.
	virtual void craft(Character* c) = 0;

protected:
	string name;
	Symbol* symbol;
	int posX, posY;

};

// Enchanting table. Craft by adding 3 EnchantingMats, 1 EnchantingCatalyst, and an Item.
class Thaumaturgy : public CraftingStation{
public:
	// Creates a new enchanting table. Pushes back all possible enchants it can do.
	Thaumaturgy();
	~Thaumaturgy();
	
	// Checks if the given mats is a possible enchant. Then enchants the item with the enchant.
	void enchant(EnchantingMat* m1, EnchantingMat* m2, EnchantingMat* m3, EnchantingCatalyst* c, Item* i);

	// UI and implementation of the enchanting table. Prints a pretty UI and allows for input of Mats and Items.
	void craft(Character* c);

	// Adds Mats/Items to the table for enchanting.
	void setToEnchant(Item* i){ toEnchant = i; }
	void setEnchantMat(EnchantingMat* i);
	void setCatalyst(EnchantingCatalyst* i);

private:
	vector<Enchant*> enchants;

	EnchantingMat *mat1, *mat2, *mat3;
	EnchantingCatalyst *cat;
	Item *toEnchant;

	// UI for the enchanting table/
	void printEnchantingScreen();

};




#endif