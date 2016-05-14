#include "Weapon.h"

Weapon::Weapon() : Item(){}

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
}