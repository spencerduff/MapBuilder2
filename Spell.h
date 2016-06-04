#ifndef SPELL_H
#define SPELL_H

#include "Weapon.h"
#include "Character.h"
#include "Velocity.h"

class Spell{
public:
	virtual void cast(float staffMag, Map* m = NULL) = 0;
	virtual void setMagnitude() = 0;

	string getName(){ return name; }
	float getLevel(){ return level; }

protected:
	Character* owner;
	float level;
	string name;
	string description;
	int cooldown;
	int currentCooldown;
	float manaCost;
	float magnitude;
};

class Fireball : public Spell{
public:
	Fireball(Character* c);
	void cast(float staffMag, Map* m = NULL) override;
	void setMagnitude() override;

private:

};

class HealSelf : public Spell{
public:
	HealSelf(Character* c);
	void cast(float staffMag, Map* m = NULL) override;

	void setTurns();
	void setMagnitude();

private:
	int turns;

};

#endif