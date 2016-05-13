#include "Weapon.h"

Leafblade::Leafblade(){
	setName("Leafblade");
	setWeight(0.0);
	setSymbol('/');
	damage = 0.26;
	speed = 0.6;
	maxDura = 999.0;
	dura = maxDura;
	maker = "The World";
	weaponRank = 0;

}