#include "Armor.h"
#include "Weapon.h"

struct Damage{
	float damage;
	DamageType damageType;
	int numOfHits;
};

class CharacterStats{
public:
	CharacterStats();
	CharacterStats(float iHP, float iStam, float iMana, float iStr, float iVit, float iDex, float iQuick, float iIntel, float iWis);
	~CharacterStats();
	void resetProts();
	void resetEncumbrance();
	void addProts(Armor *a);
	string printStats();
	string printFullStats();
	void damage(Damage amount);


	float getStr(){ return str; }
	float getHP(){ return currhp; }
	float getQuick(){ return quick; }

	float getProtSlashing(){ return slashingProt; }
	float getProtBludgeoning(){ return bludgeoningProt; }
	float getProtArrow(){ return arrowProt; }
	float getProtPiercing(){ return piercingProt; }

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
	float hp, stam, mana;
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