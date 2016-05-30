#ifndef CHARACTER_H
#define CHARACTER_H


#include <Windows.h>
#include <conio.h>
#include "Inventory.h"
#include "CharacterStats.h"
#include "AI.h"

class Item;
class AI;

enum RacialAlignment{OrkMahirim, HumanDwarfMirdain, Alfar, evil, monster};

class Character{
public:
	Character();
	virtual ~Character();
	Character(int x, int y);
	void setPos(int x, int y);
	string moveChar(char m = NULL);

	char getChar();
	char getMovement();
	int getXpos();
	int getYpos();
	float getHP();
	string getName();
	AI* getAI();

	void setMovement(char m);

	string equip(Item *equippable, bool &result);
	Paperdoll* getPaperdoll(){ return paperdoll; }
	string interactCharacter(Character* c);

protected:
	string name;
	RacialAlignment racialAlignment;
	int xPos, yPos;
	char movement;
	char character;
	Inventory *backpack;
	Paperdoll *paperdoll;
	CharacterStats *stats;
	bool isMovement(char m);
	string examineItem();
	string putOnGear();
	void updateProts();
	string calculateMeleeDamage(Character* c);
	string damage(Damage incDamage);
	AI* ai;

};

class NPC : public Character{
public:
	NPC() : Character() {}
	virtual ~NPC() {}
	void equipAll();

protected:

};

class Goblin : public NPC{
public:
	Goblin(Map* m);
	~Goblin();

private:

};



#endif // !CHARACTER_H