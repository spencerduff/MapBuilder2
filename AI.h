#ifndef AI_H
#define AI_H

class Map;
class Character;

#include "Map.h"
#include "Character.h"

class AI{
public:
	virtual void move() = 0;

protected:
	Map* currMap;
	Character* me;
};


class MeleeAI : public AI{
public:
	//Takes a map pointer(currMap) and a character pointer(itself)
	MeleeAI(Map* iMap, Character* iChar);
protected:
	void move() override;

};

#endif