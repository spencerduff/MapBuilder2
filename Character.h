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
	string moveChar(char m = NULL);

	char getChar();
	char getMovement();
	int getXpos();
	int getYpos();
	float getHP();
	string getName();

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