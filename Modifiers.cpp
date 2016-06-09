#include "Modifiers.h"

HealingModifier::HealingModifier(int t, float m, Character* c){
	magnitude = m;
	turns = t;
	owner = c;
}

void HealingModifier::tick(){
	owner->heal(magnitude);
	cout << owner->getName() << " has been healed for " << magnitude << " points of health." << endl;
	turns--;
}

RegenerationModifier::RegenerationModifier(int t, float m, Character* c, bool br){
	magnitude = m;
	turns = t;
	owner = c;
	baseRegen = br;
}

void RegenerationModifier::tick(){
	float r = ((float)rand() / (RAND_MAX));
	if (magnitude >= r){
		owner->heal(1);
		owner->healStam(1);
		owner->healMana(1);
	}
	if (baseRegen)
		return;
	else turns--;
}