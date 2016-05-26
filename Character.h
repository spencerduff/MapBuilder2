#ifndef CHARACTER_H
#define CHARACTER_H


#include <Windows.h>
#include <conio.h>
#include "Inventory.h"
#include "CharacterStats.h"

class Item;

enum RacialAlignment{OrkMahirim, HumanDwarfMirdain, Alfar, evil, monster};

class Character{
public:
	Character();
	virtual ~Character();
	Character(int x, int y);
	void setPos(int x, int y);
	void moveChar(char m = NULL);

	char getChar();
	char getMovement();
	int getXpos();
	int getYpos();
	float getHP();
	string getName();

	bool equip(Item *equippable);
	Paperdoll* getPaperdoll(){ return paperdoll; }
	void interactCharacter(Character* c);

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
	void examineItem();
	void putOnGear();
	void updateProts();
	void calculateMeleeDamage(Character* c);
	void damage(Damage incDamage);

};

//class NPC : Character{
//public:
//	NPC() : Character() {}
//
//protected:
//	void changeRacialAlignment(RacialAlignment a){ racialAlignment = a; }
//	Inventory* getBackpack(){ return backpack; }
//
//};

class Goblin : public Character{
public:
	Goblin();
	~Goblin();

private:

};



#endif // !CHARACTER_H