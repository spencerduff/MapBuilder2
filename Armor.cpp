#include "Armor.h"
#include "Character.h"
#include <iomanip>

Armor::Armor(Inventory* p) : Item(p){}

Armor::~Armor(){

}

Armor::Armor(const Armor& rhs) : Item(rhs){
	this->maker = rhs.maker;
	this->encumbrance = rhs.encumbrance;
	this->dura = rhs.dura;
	this->duraMax = rhs.duraMax;
	this->prots = rhs.prots;
	this->piece = rhs.piece;
}

Item* Armor::clone(){
	return new Armor(*this);
}

void Armor::equip(Character *c){
	switch (this->piece) {
	case helm:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->helm));
		c->getPaperdoll()->setHelm(this);
		break;
	case chest:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->chest));
		c->getPaperdoll()->setChest(this);
		break;
	case legs:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->legs));
		c->getPaperdoll()->setLegs(this);
		break;
	case greaves:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->greaves));
		c->getPaperdoll()->setGreaves(this);
		break;
	case gauntlets:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->gauntlets)); 
		c->getPaperdoll()->setGauntlets(this);
		break;
	case elbows:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->elbows)); 
		c->getPaperdoll()->setElbows(this);
		break;
	case boots:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->boots)); 
		c->getPaperdoll()->setBoots(this);
		break;
	case vambraces:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->vambraces)); 
		c->getPaperdoll()->setVambraces(this);
		break;
	case girdle:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->girdle)); 
		c->getPaperdoll()->setGirdle(this);
		break;
	case shoulders:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->shoulders)); 
		c->getPaperdoll()->setShoulders(this);
		break;
	case necklace:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->necklace)); 
		c->getPaperdoll()->setNecklace(this);
		break;
	case ring:
		if (c->getPaperdoll()->rhRing != NULL){
			(c->getPaperdoll()->unequip(c->getPaperdoll()->lhRing));
			c->getPaperdoll()->setLhRing(this);
		}
		else
			c->getPaperdoll()->setRhRing(this);
		break;
	case earring:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->earring)); 
		c->getPaperdoll()->setEarring(this);
		break;
	case robe: c->getPaperdoll()->setRobe(this);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->helm));
		c->getPaperdoll()->setHelm(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->chest));
		c->getPaperdoll()->setChest(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->legs));
		c->getPaperdoll()->setLegs(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->greaves));
		c->getPaperdoll()->setGreaves(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->gauntlets));
		c->getPaperdoll()->setGauntlets(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->elbows));
		c->getPaperdoll()->setElbows(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->boots));
		c->getPaperdoll()->setBoots(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->vambraces));
		c->getPaperdoll()->setVambraces(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->girdle));
		c->getPaperdoll()->setGirdle(NULL);
		(c->getPaperdoll()->unequip(c->getPaperdoll()->shoulders));
		c->getPaperdoll()->setShoulders(NULL);
		break;
	case shield:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->shield)); 
		c->getPaperdoll()->setShield(this);
		break;
	}
}

void Armor::examine(){
	cout << getName() << endl;
	getSymbol()->printSymbol();
	cout << endl;
	cout << "Weight: " << setprecision(2) << fixed << getWeight() << endl;
	cout << "Durability: ";
	cout << setprecision(2) << fixed << dura << "/" << setprecision(2) << fixed << duraMax << endl;
	cout << "Encumbrance: " << setprecision(2) << fixed << encumbrance << endl << endl;
	cout << "Protections... " << endl;
	if (prots.protAcid > 0)
		cout << "Acid: " << setprecision(2) << fixed << prots.protAcid << endl;
	if (prots.protArcane > 0)
		cout << "Arcane: " << setprecision(2) << fixed << prots.protArcane << endl;
	if (prots.protBludgeoning > 0)
		cout << "Bludgeoning: " << setprecision(2) << fixed << prots.protBludgeoning << endl;
	if (prots.protCold > 0)
		cout << "Cold: " << setprecision(2) << fixed << prots.protCold << endl;
	if (prots.protFire > 0)
		cout << "Fire: " << setprecision(2) << fixed << prots.protFire << endl;
	if (prots.protHoly > 0)
		cout << "Holy: " << setprecision(2) << fixed << prots.protHoly << endl;
	if (prots.protImpact > 0)
		cout << "Impact: " << setprecision(2) << fixed << prots.protImpact << endl;
	if (prots.protLightning > 0)
		cout << "Lightning: " << setprecision(2) << fixed << prots.protLightning << endl;
	if (prots.protPiercing > 0)
		cout << "Piercing: " << setprecision(2) << fixed << prots.protPiercing << endl;
	if (prots.protSlashing > 0)
		cout << "Slashing: " << setprecision(2) << fixed << prots.protSlashing << endl;
	if (prots.protUnholy > 0)
		cout << "Unholy: " << setprecision(2) << fixed << prots.protUnholy << endl;
}

void Armor::addToEnchantingTable(Thaumaturgy *t){
	t->setToEnchant(this);
}

DragonChest::DragonChest(Inventory* p) : Armor(p){
	setName("Dragon Armor Cuirass");
	setWeight(5.0);
	setSymbol(new Symbol(']', 15));
	duraMax = 60.50;
	dura = duraMax;
	encumbrance = 42.00;
	maker = "The World";
	setItemID(getNextID());
	piece = chest;
	prots.protAcid = prots.protCold = prots.protFire = prots.protHoly = prots.protUnholy = float(7.69);
	prots.protBludgeoning = prots.protImpact = float(3.59);
	prots.protLightning = float(5.71);
	prots.protPiercing = float(4.05);
	prots.protSlashing = float(4.50);
	prots.protArcane = 0;
	equipped = false;
}

DragonChest::~DragonChest(){

}
