#ifndef SPELL_H
#define SPELL_H

#include "Weapon.h"
#include "Character.h"
#include "Velocity.h"

// Spells are held in a Spellbook. Each casts and sets its magnitude differently
class Spell{
public:
	// Each spells casts and sets magnitude differently
	virtual void cast(float staffMag, Map* m = NULL) = 0;
	virtual void setMagnitude() = 0;

	// Getters
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
	// Pops the projectile out on the right side and then spends mana.
	void cast(float staffMag, Map* m = NULL) override;
	// Sets a reasonable dmg to it.
	void setMagnitude() override;

private:

};

class HealSelf : public Spell{
public:
	HealSelf(Character* c);
	// Gives the caster a healing modifier, then spends mana.
	void cast(float staffMag, Map* m = NULL) override;

	// Sets turns and magnitude based on level and other things.
	void setTurns();
	void setMagnitude();

private:
	int turns;

};

#endif