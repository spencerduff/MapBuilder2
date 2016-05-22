#include "Armor.h"
#include "Character.h"

void Armor::equip(Character *c){
	switch (this->piece) {
	case helm: c->getPaperdoll()->setHelm(this);
		break;
	case chest: c->getPaperdoll()->setChest(this);
		break;
	case legs: c->getPaperdoll()->setLegs(this);
		break;
	case greaves: c->getPaperdoll()->setGreaves(this);
		break;
	case gauntlets: c->getPaperdoll()->setGauntlets(this);
		break;
	case elbows: c->getPaperdoll()->setElbows(this);
		break;
	case boots: c->getPaperdoll()->setBoots(this);
		break;
	case vambraces: c->getPaperdoll()->setVambraces(this);
		break;
	case girdle: c->getPaperdoll()->setGirdle(this);
		break;
	case shoulders: c->getPaperdoll()->setShoulders(this);
		break;
	case necklace: c->getPaperdoll()->setNecklace(this);
		break;
	case ring:
		if (c->getPaperdoll()->rhRing != NULL)
			c->getPaperdoll()->setLhRing(this);
		else
			c->getPaperdoll()->setRhRing(this);
		break;
	case earring: c->getPaperdoll()->setEarring(this);
		break;
	case robe: c->getPaperdoll()->setRobe(this);
		c->getPaperdoll()->setHelm(NULL);
		c->getPaperdoll()->setChest(NULL);
		c->getPaperdoll()->setLegs(NULL);
		c->getPaperdoll()->setGreaves(NULL);
		c->getPaperdoll()->setGauntlets(NULL);
		c->getPaperdoll()->setElbows(NULL);
		c->getPaperdoll()->setBoots(NULL);
		c->getPaperdoll()->setVambraces(NULL);
		c->getPaperdoll()->setGirdle(NULL);
		c->getPaperdoll()->setShoulders(NULL);
		break;
	case shield: c->getPaperdoll()->setShield(this);
		break;
	}


}