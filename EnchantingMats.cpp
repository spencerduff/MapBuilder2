#include "EnchantingMats.h"
#include "Crafting.h"
#include <iomanip>

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

void EnchantingMat::addStacks(Item* i){
	addStack(i->getStack());
	delete i;
}

int EnchantingMat::getStack(){
	return stack;
}

void EnchantingCatalyst::addStacks(Item* i){
	addStack(i->getStack());
	delete i;
}

int EnchantingCatalyst::getStack(){
	return stack;
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

void EnchantingMat::examine(){
	cout << "(" << stack << ") ";
	cout << getName() << endl;
	getSymbol()->printSymbol();
	cout << endl;
	cout << "Weight: " << setprecision(2) << fixed << totWeight << endl;
	cout << "Quality: " << floor(quality + .5) << endl;
}

void EnchantingCatalyst::examine(){
	cout << "(" << stack << ") ";
	cout << getName() << endl;
	getSymbol()->printSymbol();
	cout << endl;
	cout << "Weight: " << setprecision(2) << fixed << totWeight << endl;
}

Bile::Bile(Inventory* p, float iquality, int istack) : EnchantingMat(bile, iquality, istack, p){
	stringstream ss;
	ss << "Q";
	ss << floor(quality + .5);
	ss << " Bile";
	setName(ss.str());
	setSymbol(new Symbol('?', 14));
	setWeight(0.01);
	totWeight = getWeight()*stack;
	setItemID(getNextID());
}

Cinder::Cinder(Inventory* p, float iquality, int istack) : EnchantingMat(cinder, iquality, istack, p){
	stringstream ss;
	ss << "Q";
	ss << floor(quality + .5);
	ss << " Cinder";
	setName(ss.str());
	setSymbol(new Symbol('?', 8));
	setWeight(0.01);
	totWeight = getWeight()*stack;
	setItemID(getNextID());
}

Darktaint::Darktaint(Inventory* p, float iquality, int istack) : EnchantingMat(darktaint, iquality, istack, p){
	stringstream ss;
	ss << "Q";
	ss << floor(quality + .5);
	ss << " Darktaint";
	setName(ss.str());
	setSymbol(new Symbol('?', 1));
	setWeight(0.01);
	totWeight = getWeight()*stack;
	setItemID(getNextID());
}

Numen::Numen(Inventory* p, int istack) : EnchantingCatalyst(numen, istack, p){
	setName("Numen");
	setSymbol(new Symbol('?', 13));
	setWeight(0.05);
	totWeight = getWeight()*stack;
	setItemID(getNextID());
}