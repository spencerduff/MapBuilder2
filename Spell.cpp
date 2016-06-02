#include "Spell.h"

//Fireball::Fireball(){
//
//
//
//}
//
//void Fireball::cast(){
//
//}


HealSelf::HealSelf(Character* c){
	owner = c;
	name = "Heal Self";
	description = "A wave of healing energies washes over the caster.";
	level = 1.00;
	posX = posY = NULL;
	setTurns();
	setMagnitude();
	cooldown = 30;
	currentCooldown = 0;
	manaCost = 10 - (2 * owner->getStats()->getIntel() / 100);
}

void HealSelf::setTurns(){
	if (level >= 1 && level <= 33.33)
		turns = 3;
	else if (level >= 33.33 && level <= 66.66)
		turns = 4;
	else if (level >= 66.66)
		turns = 5;
	else
		turns = 5;
}

void HealSelf::setMagnitude(){
	magnitude = 5.0 + (level / 30);
	magnitude += (owner->getStats()->getIntel() / 10);
}

void HealSelf::cast(float staffMag){
	if (owner->getStats()->getMana() < manaCost){
		cout << "Not enough mana to cast " << name << "." << endl;
		return;
	}
	owner->addMod(new HealingModifier(turns, (magnitude * (1 + staffMag)), owner));
	owner->getStats()->spendMana(manaCost);
}