#include "Armor.h"
#include "Weapon.h"

class CharacterStats{
public:
	CharacterStats();
	void resetProts();
	void addProts(Armor *a);
	void printStats();
	void printFullStats();

private:
	///Status///
	const int maxStat = 450;
	float hp, stam, mana;
	float currhp, currstam, currmana;
	int alignment;

	///Base Attributes///
	const int maxAttribute = 100;
	float str, vit, dex, quick, intel, wis;
	
	///Armor Penalties///
	float encumberance;
	
	///Protections///
	//Physical
	float arrow, bludgeoning, piercing, slashing;
	//Elemental
	float acid, arcane, cold, fire, holy, impact, lightning, unholy;
	//Body
	float malediction, mental, infliction;
};