#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Character;

enum Type { primary, quiver };

class Weapon : public Item{
public:
	void setName(string newName){ name = newName; }
	void setSymbol(char newSymbol){ symbol = newSymbol; }
	void setWeight(float newWeight){ weight = newWeight; }
	Type type;
	Weapon();
	void equip(Character *c) override;
	void examine() override;

protected:
	float damage;
	float speed;
	float dura;
	float duraMax;
	string maker;
	int weaponRank;

};

class Leafblade : public Weapon{
public:
	Leafblade();

private:
	void setNameOfWep(string name){ setName(name); }
	void setSymbolOfWep(char symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }

};

#endif