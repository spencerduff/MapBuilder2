#include "Armor.h"
#include "Weapon.h"

struct Damage{
	float damage;
	DamageType damageType;
	int numOfHits;
};

// Stats of a Character. All the HP/Stam/Mana, Protections, and Attributes.
class CharacterStats{
public:
	// Makes the default player CharacterStats
	CharacterStats();
	CharacterStats(float iHP, float iStam, float iMana, float iStr, float iVit, float iDex, float iQuick, float iIntel, float iWis);
	~CharacterStats();
	// Sets all the protections to 0. Used when updating protections so armor is only counted once.
	void resetProts();
	// Resets the encumbrance to 0. Used when updating protections so armor is only counted once.
	void resetEncumbrance();
	// Adds the protections of an Armor to a Character's stats.
	void addProts(Armor *a);
	// Function to print stats of a Character (only HP/Stam/Mana and alignment)
	void printStats();
	// Prints all stats of a Character.
	void printFullStats();
	// Damages the stats of a character based on protections and damage type.
	void damage(Damage amount);
	// Heals the HP of a Character for an amount
	void healHP(float amount);
	// Spends Mana of a Character. Called when a spell is cast.
	void spendMana(float amount);

	// Getters
	float getHP(){ return currhp; }
	float getMana(){ return currmana; }
	float getStr(){ return str; }
	float getQuick(){ return quick; }
	float getIntel(){ return intel; }

	float getProtSlashing(){ return slashingProt; }
	float getProtBludgeoning(){ return bludgeoningProt; }
	float getProtArrow(){ return arrowProt; }
	float getProtPiercing(){ return piercingProt; }
	float getProtFire(){ return fireProt; }

	//Setters
	void setHP(float newHP);
	void setStam(float newStam);
	void setMana(float newMana);
	void setStr(float newStr);
	void setVit(float newVit);
	void setDex(float newDex);
	void setQuick(float newQuick);
	void setIntel(float newIntel);
	void setWis(float newWis);


private:
	///Status///
	const int maxPlayerStat = 450;
	float hpMax, stamMax, manaMax;
	float currhp, currstam, currmana;
	int alignment;

	///Base Attributes///
	const int maxAttribute = 100;
	float str, vit, dex, quick, intel, wis;
	
	///Armor Penalties///
	float encumbrance;
	
	///Protections///
	//Physical
	float arrowProt, bludgeoningProt, piercingProt, slashingProt;
	//Elemental
	float acidProt, arcaneProt, coldProt, fireProt, holyProt, impactProt, lightningProt, unholyProt;
	//Body
	float maledictionProt, mentalProt, inflictionProt;
};