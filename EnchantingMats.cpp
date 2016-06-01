#include "EnchantingMats.h"
#include "Crafting.h"

EnchantingMat::EnchantingMat(Material m, float q, int istack, Inventory* p) : Item(p){
	material = m;
	quality = q;
	stack = istack;
	stackable = true;
}

EnchantingCatalyst::EnchantingCatalyst(Catalyst c, int istack, Inventory* p) : Item(p){
	catalyst = c;
	stack = istack;
	stackable = true;
}

void EnchantingMat::addToEnchantingTable(Thaumaturgy *t){
	t->setEnchantMat(this);
}

void EnchantingCatalyst::addToEnchantingTable(Thaumaturgy *t){
	t->setCatalyst(this);
}

void EnchantingMat::decrementStack(){
	stack--;
	if (stack == 0)
		delete this;
}

void EnchantingCatalyst::decrementStack(){
	stack--;
	if (stack == 0)
		delete this;
}

Bile::Bile(Inventory* p, float iquality, int istack) : EnchantingMat(bile, iquality, istack, p){
	setName("Bile");
	setSymbol(new Symbol('?', NULL, NULL, 14));
	setWeight(0.01*stack);
	setItemID(getNextID());
}

Cinder::Cinder(Inventory* p, float iquality, int istack) : EnchantingMat(cinder, iquality, istack, p){
	setName("Cinder");
	setSymbol(new Symbol('?', NULL, NULL, 8));
	setWeight(0.01*stack);
	setItemID(getNextID());
}

Darktaint::Darktaint(Inventory* p, float iquality, int istack) : EnchantingMat(darktaint, iquality, istack, p){
	setName("Darktaint");
	setSymbol(new Symbol('?', NULL, NULL, 1));
	setWeight(0.01*stack);
	setItemID(getNextID());
}

Numen::Numen(Inventory* p, int istack) : EnchantingCatalyst(numen, istack, p){
	setName("Numen");
	setSymbol(new Symbol('?', NULL, NULL, 13));
	setWeight(0.05*stack);
	setItemID(getNextID());
}