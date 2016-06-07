#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <vector>
#include "Spell.h"

using namespace std;

// Each Character has a Spellbook. A Spellbook holds the list of known spells.
class Spellbook{
public:
	Spellbook(Character* c);
	// Teaches the owner a new Spell.
	void learn(Spell* s);

	// Prints Spellbook UI
	void printSpellbook();

	// For choosing a spell.
	int parsePosInSpellbook(char input);
	vector<Spell*> spellList;

protected:
	Character* owner;

};

#endif