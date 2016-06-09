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

Item* EnchantingMat::clone(){
	return new EnchantingMat(*this);
}

Item* EnchantingCatalyst::clone(){
	return new EnchantingCatalyst(*this);
}

EnchantingMat::EnchantingMat(const EnchantingMat &obj) : Item(obj){
	this->stackable = obj.stackable;
	this->stack = obj.stack;
}

EnchantingCatalyst::EnchantingCatalyst(const EnchantingCatalyst &obj) : Item(obj){
	this->stackable = obj.stackable;
	this->stack = obj.stack;
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

Item* Bile::clone(){
	return new Bile(*this);
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

Item* Cinder::clone(){
	return new Cinder(*this);
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

Item* Darktaint::clone(){
	return new Darktaint(*this);
}

Tooth::Tooth(Inventory* p, float iquality, int istack) : EnchantingMat(tooth, iquality, istack, p){
	stringstream ss;
	ss << "Q";
	ss << floor(quality + .5);
	ss << " Tooth";
	setName(ss.str());
	setSymbol(new Symbol('?', 6));
	setWeight(0.01);
	totWeight = getWeight()*stack;
	setItemID(getNextID());
}

Item* Tooth::clone(){
	return new Tooth(*this);
}

Numen::Numen(Inventory* p, int istack) : EnchantingCatalyst(numen, istack, p){
	setName("Numen");
	setSymbol(new Symbol('?', 13));
	setWeight(0.05);
	totWeight = getWeight()*stack;
	setItemID(getNextID());
}

Item* Numen::clone(){
	return new Numen(*this);
}