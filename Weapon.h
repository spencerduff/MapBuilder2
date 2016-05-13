#include "Item.h"

class Weapon : public Item{
public:
	void setName(string newName){ name = newName; }
	void setSymbol(char newSymbol){ symbol = newSymbol; }
	void setWeight(float newWeight){ weight = newWeight; }

protected:
	float damage;
	float speed;
	float dura;
	float maxDura;
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