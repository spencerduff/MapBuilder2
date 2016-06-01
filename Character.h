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
	void moveChar(char m = NULL);

	Symbol* getChar();
	char getMovement();
	int getXpos();
	int getYpos();
	float getHP();
	string getName();
	AI* getAI();
	Inventory* getBackpack(){ return backpack; }
	Paperdoll* getPaperdoll(){ return paperdoll; }

	void setMovement(char m);

	void equip(Item *equippable, bool &result);
	void interactCharacter(Character* c);
	void unequipAll();
	void clearPastMap();
	void putCursorPastMap();

protected:
	string name;
	RacialAlignment racialAlignment;
	int xPos, yPos;
	char movement;
	Symbol* character;
	Inventory *backpack;
	Paperdoll *paperdoll;
	CharacterStats *stats;
	AI* ai;

	bool isMovement(char m);
	void examineItem();
	void putOnGear();
	void updateProts();
	void calculateMeleeDamage(Character* c);
	void damage(Damage incDamage);
	void damageArmor();

private:


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