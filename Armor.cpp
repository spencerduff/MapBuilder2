#include "Armor.h"
#include "Character.h"
#include <iomanip>

Armor::Armor() : Item(){}

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
	cout << name << endl;
	cout << symbol << endl;
	cout << "Weight: " << setprecision(2) << fixed << weight << endl;
	cout << "Durability: ";
	cout << setprecision(2) << fixed << dura << "/" << setprecision(2) << fixed << duraMax << endl;
	cout << "Encumberance: " << setprecision(2) << fixed << encumberance << endl;
	cout << "Protections... " << endl;
	cout << "Acid: " << setprecision(2) << fixed << protAcid << endl;
	cout << "Bludgeoning: " << setprecision(2) << fixed << protBludgeoning << endl;
	cout << "Cold: " << setprecision(2) << fixed << protCold << endl;
	cout << "Fire: " << setprecision(2) << fixed << protFire << endl;
	cout << "Holy: " << setprecision(2) << fixed << protHoly << endl;
	cout << "Impact: " << setprecision(2) << fixed << protImpact << endl;
	cout << "Lightning: " << setprecision(2) << fixed << protLightning << endl;
	cout << "Piercing: " << setprecision(2) << fixed << protPiercing << endl;
	cout << "Slashing: " << setprecision(2) << fixed << protSlashing << endl;
	cout << "Unholy: " << setprecision(2) << fixed << protUnholy << endl;
}


DragonChest::DragonChest() : Armor(){
	setName("Dragon Armor Cuirass");
	setWeight(5.0);
	setSymbol(']');
	duraMax = 60.50;
	dura = duraMax;
	encumberance = 42.00;
	maker = "The World";
	itemID = nextID;
	piece = chest;
	protAcid = protCold = protFire = protHoly = protUnholy = 7.69;
	protBludgeoning = protImpact = 3.59;
	protLightning = 5.71;
	protPiercing = 4.05;
	protSlashing = 4.50;
	equipped = false;
}


float encumberance;
float dura;
float duraMax;
float protBludgeoning, protSlashing, protPiercing, protAcid, protCold, protFire, protHoly, protLightning, protUnholy, protImpact;