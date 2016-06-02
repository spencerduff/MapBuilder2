#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <vector>
#include "Spell.h"

using namespace std;

class Spellbook{
public:
	Spellbook(Character* c);
	void learn(Spell* s);

	void printSpellbook();

	int parsePosInSpellbook(char input);
	vector<Spell*> spellList;

protected:
	Character* owner;

};

#endif