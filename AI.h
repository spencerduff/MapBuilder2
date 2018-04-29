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

	AI(int p);

	void setAttacked(){ attacked = true; }

	bool isAttacked(){ return attacked; }

	virtual void tellOthers();

protected:
	// The map a character is on.
	Map* currMap;
	// The character associated with the AI
	Character* me;

	bool attacked;

	int m_perception;

	std::string createPath(Character* toChar);

	bool inPerception(int x, int y);

private:
	char getNextMove(int x, int y, int destX, int destY);
};


class MeleeAI : public AI{
public:
	// Takes a map pointer(currMap) and a character pointer(itself)
	MeleeAI(Map* iMap, Character* iChar, int p);
protected:
	// If the player character is within 10 spaces of me, move toward him.
	// It will attack if within one space.
	void move() override;

};

class MediumSmartAI : public AI{
public:
	MediumSmartAI(Map* iMap, Character* iChar, int p);

protected:
	void move() override;
};


class SmartAI : public AI{
public:
	SmartAI(Map* iMap, Character* iChar, int p);

protected:
	void move() override;
	void tellOthers() override;
};

class TalkingAI : public AI{
public:
	// Takes a map pointer(currMap) and a character pointer(itself)
	TalkingAI(Map* iMap, Character* iChar, int p);
protected:
	// If the player character is within 10 spaces of me, move toward him.
	// It will attack if within one space.
	void move() override;
};

#endif