#ifndef AI_H
#define AI_H

class Map;
class Character;

#include "Map.h"
#include "Character.h"

/* Every Character has an AI. The Player Character's AI is NULL. Different Characters will use different types of AI. */
class AI{
public:
	// How a character decides to move.
	virtual void move() = 0;

	void setAttacked(){ attacked = true; }

protected:
	// The map a character is on.
	Map* currMap;
	// The character associated with the AI
	Character* me;

	bool attacked;
};


class MeleeAI : public AI{
public:
	// Takes a map pointer(currMap) and a character pointer(itself)
	MeleeAI(Map* iMap, Character* iChar);
protected:
	// If the player character is within 10 spaces of me, move toward him.
	// It will attack if within one space.
	void move() override;

};

#endif