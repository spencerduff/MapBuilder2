#ifndef CRAFTING_H
#define CRAFTING_H

#include "Enchants.h"
#include <vector>

class CraftingStation{
public:
	void setPos(int x, int y);

	int getXpos(){ return posX; }
	int getYpos(){ return posY; }
	char getChar(){ return symbol; }

	virtual void craft(Character* c) = 0;

protected:
	string name;
	char symbol;
	int posX, posY;

};

class Thaumaturgy : public CraftingStation{
public:
	Thaumaturgy();
	void enchant(EnchantingMat* m1, EnchantingMat* m2, EnchantingMat* m3, EnchantingCatalyst* c, Item* i);

	void craft(Character* c);

	void setToEnchant(Item* i){ toEnchant = i; }
	void setEnchantMat(EnchantingMat* i);
	void setCatalyst(EnchantingCatalyst* i);

private:
	vector<Enchant*> enchants;

	EnchantingMat *mat1, *mat2, *mat3;
	EnchantingCatalyst *cat;
	Item *toEnchant;

	void printEnchantingScreen();

};




#endif