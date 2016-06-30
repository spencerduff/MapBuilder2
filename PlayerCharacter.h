#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include "Character.h"

enum Race { Ork, Mahirim, Human, Elf, Dwarf, Alfar };

class PlayerCharacter : public Character{
public:
	PlayerCharacter(Map* m);




private:
	const static string races[6];
	Race race;

	void namePrompt();
	void racePrompt();
	void openingScreen();
};

#endif