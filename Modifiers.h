#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "Spell.h"
#include "Character.h"

// Modifiers are effects on a Character. They tick every time the Map updates.
class Modifier{
public:
	// Overridable function to tick the modifier. Some modifiers heal or damage the Character that owns them each tick
	virtual void tick() = 0;

	// Getter
	int getTurns(){ return turns; }

protected:
	int turns;
	float magnitude;
	Character* owner;
};


class HealingModifier : public Modifier{
public:
	// Needs to know the owner to apply modifier to it.
	HealingModifier(int t, float m, Character* c);
	// Heals the owner and reduces the number of ticks left.
	void tick() override;

private:

};


#endif;