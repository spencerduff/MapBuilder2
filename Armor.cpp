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

string Armor::equip(Character *c){
	stringstream ss;
	switch (this->piece) {
	case helm:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->helm));
		ss << c->getPaperdoll()->setHelm(this);
		break;
	case chest:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->chest));
		ss << c->getPaperdoll()->setChest(this);
		break;
	case legs:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->legs));
		ss << c->getPaperdoll()->setLegs(this);
		break;
	case greaves:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->greaves));
		ss << c->getPaperdoll()->setGreaves(this);
		break;
	case gauntlets:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->gauntlets)); 
		ss << c->getPaperdoll()->setGauntlets(this);
		break;
	case elbows:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->elbows)); 
		ss << c->getPaperdoll()->setElbows(this);
		break;
	case boots:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->boots)); 
		ss << c->getPaperdoll()->setBoots(this);
		break;
	case vambraces:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->vambraces)); 
		ss << c->getPaperdoll()->setVambraces(this);
		break;
	case girdle:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->girdle)); 
		ss << c->getPaperdoll()->setGirdle(this);
		break;
	case shoulders:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->shoulders)); 
		ss << c->getPaperdoll()->setShoulders(this);
		break;
	case necklace:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->necklace)); 
		ss << c->getPaperdoll()->setNecklace(this);
		break;
	case ring:
		if (c->getPaperdoll()->rhRing != NULL){
			(c->getPaperdoll()->unequip(c->getPaperdoll()->lhRing));
			ss << c->getPaperdoll()->setLhRing(this);
		}
		else
			ss << c->getPaperdoll()->setRhRing(this);
		break;
	case earring:
		(c->getPaperdoll()->unequip(c->getPaperdoll()->earring)); 
		ss << c->getPaperdoll()->setEarring(this);
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
		ss << c->getPaperdoll()->setShield(this);
		break;
	}
	return ss.str();
}

string Armor::examine(){
	stringstream ss;
	ss << getName() << endl;
	ss << getSymbol() << endl;
	ss << "Weight: " << setprecision(2) << fixed << getWeight() << endl;
	ss << "Durability: ";
	ss << setprecision(2) << fixed << dura << "/" << setprecision(2) << fixed << duraMax << endl;
	ss << "Encumbrance: " << setprecision(2) << fixed << encumbrance << endl << endl;
	ss << "Protections... " << endl;
	if (prots.protAcid > 0)
		ss << "Acid: " << setprecision(2) << fixed << prots.protAcid << endl;
	if (prots.protArcane > 0)
		ss << "Arcane: " << setprecision(2) << fixed << prots.protArcane << endl;
	if (prots.protBludgeoning > 0)
		ss << "Bludgeoning: " << setprecision(2) << fixed << prots.protBludgeoning << endl;
	if (prots.protCold > 0)
		ss << "Cold: " << setprecision(2) << fixed << prots.protCold << endl;
	if (prots.protFire > 0)
		ss << "Fire: " << setprecision(2) << fixed << prots.protFire << endl;
	if (prots.protHoly > 0)
		ss << "Holy: " << setprecision(2) << fixed << prots.protHoly << endl;
	if (prots.protImpact > 0)
		ss << "Impact: " << setprecision(2) << fixed << prots.protImpact << endl;
	if (prots.protLightning > 0)
		ss << "Lightning: " << setprecision(2) << fixed << prots.protLightning << endl;
	if (prots.protPiercing > 0)
		ss << "Piercing: " << setprecision(2) << fixed << prots.protPiercing << endl;
	if (prots.protSlashing > 0)
		ss << "Slashing: " << setprecision(2) << fixed << prots.protSlashing << endl;
	if (prots.protUnholy > 0)
		ss << "Unholy: " << setprecision(2) << fixed << prots.protUnholy << endl;
	return ss.str();
}

void Armor::addToEnchantingTable(Thaumaturgy *t){
	t->setToEnchant(this);
}

DragonChest::DragonChest(Inventory* p) : Armor(p){
	setName("Dragon Armor Cuirass");
	setWeight(5.0);
	setSymbol(']');
	duraMax = 60.50;
	dura = duraMax;
	encumbrance = 42.00;
	maker = "The World";
	setItemID(getNextID());
	piece = chest;
	prots.protAcid = prots.protCold = prots.protFire = prots.protHoly = prots.protUnholy = 7.69;
	prots.protBludgeoning = prots.protImpact = 3.59;
	prots.protLightning = 5.71;
	prots.protPiercing = 4.05;
	prots.protSlashing = 4.50;
	prots.protArcane = 0;
	equipped = false;
}

DragonChest::~DragonChest(){

}
