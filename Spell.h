#ifndef SPELL_H
#define SPELL_H

#include "Weapon.h"
#include "Character.h"

struct VECTOR{
	int xDir, yDir;
	float speed;
};

class Spell{
public:
	virtual void cast(float staffMag) = 0;
	virtual void setMagnitude() = 0;
	string getName(){ return name; }
	float getLevel(){ return level; }

protected:
	Character* owner;
	int posX, posY;
	float level;
	string name;
	string description;
	int cooldown;
	int currentCooldown;
	float manaCost;
};

//class Fireball : public Spell{
//public:
//	Fireball();
//	void cast() override;
//
//private:
//	VECTOR v;
//
//};

class HealSelf : public Spell{
public:
	HealSelf(Character* c);
	void cast(float staffMag) override;

	void setTurns();
	void setMagnitude();

private:
	int turns;
	float magnitude;

};

#endif