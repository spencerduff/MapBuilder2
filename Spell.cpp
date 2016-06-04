#include "Spell.h"

Fireball::Fireball(Character* c){
	owner = c;
	name = "Fireball";
	description = "Shoots forth a fireball that explodes in a radius. Aim after casting and fire with f.";
	level = 1.00;
	setMagnitude();
	cooldown = 5;
	currentCooldown = 0;
	manaCost = 15 - (2 * owner->getStats()->getIntel() / 100);


}

void Fireball::cast(float staffMag, Map* m){
	if (owner->getStats()->getMana() < manaCost){
		cout << "Not enough mana to cast " << name << "." << endl;
		return;
	}
	Damage d;
	d.damage = magnitude * (1 + staffMag);
	d.damageType = fire;
	d.numOfHits = 1;

	Velocity v = owner->aimProjectile();
	v.speed = 5;

	int popX = owner->getXpos(), popY = owner->getYpos();

	if (v.xDir > 0)
		popX = owner->getXpos() + 1;
	if (v.yDir > 0)
		popY = owner->getYpos() + 1;
	if (v.xDir < 0)
		popX = owner->getXpos() - 1;
	if (v.yDir < 0)
		popY = owner->getYpos() - 1;

	m->addProjectile(new FireballProj(v, d, popX, popY, m));

	owner->getStats()->spendMana(manaCost);
	owner->clearPastMap();
}

//Velocity iV, Damage d, int x, int y, Map* iM
//int xDir, yDir;
//int xSpeed, ySpeed;

void Fireball::setMagnitude(){
	magnitude = 10 + (level / 2);
	magnitude += (owner->getStats()->getIntel() / 10);
}

HealSelf::HealSelf(Character* c){
	owner = c;
	name = "Heal Self";
	description = "A wave of healing energies washes over the caster.";
	level = 1.00;
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

void HealSelf::cast(float staffMag, Map* m){
	if (owner->getStats()->getMana() < manaCost){
		cout << "Not enough mana to cast " << name << "." << endl;
		return;
	}
	owner->addMod(new HealingModifier(turns, (magnitude * (1 + staffMag)), owner));
	owner->getStats()->spendMana(manaCost);
}