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