#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "Spell.h"
#include "Character.h"

class Modifier{
public:
	virtual void tick() = 0;
	int getTurns(){ return turns; }

protected:
	int turns;
	float magnitude;
	Character* owner;
};


class HealingModifier : public Modifier{
public:
	HealingModifier(int t, float m, Character* c);
	void tick() override;

private:

};


#endif;