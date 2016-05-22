#include "Weapon.h"
#include "Character.h"

Weapon::Weapon() : Item(){}

void Weapon::equip(Character *c){
	if (this->type == primary)
		c->getPaperdoll()->setPrimary(this);
	else if (this->type == quiver)
		c->getPaperdoll()->setQuiver(this);
}

Leafblade::Leafblade() : Weapon(){
	setName("Leafblade");
	setWeight(0.0);
	setSymbol('/');
	damage = 0.26;
	speed = 0.6;
	maxDura = 999.0;
	dura = maxDura;
	maker = "The World";
	weaponRank = 0;
	itemID = nextID;
	type = primary;
}

