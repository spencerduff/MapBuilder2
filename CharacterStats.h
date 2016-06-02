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
	void printStats();
	void printFullStats();
	void damage(Damage amount);
	void healHP(float amount);

	void spendMana(float amount);


	float getHP(){ return currhp; }
	float getMana(){ return currmana; }
	float getStr(){ return str; }
	float getQuick(){ return quick; }
	float getIntel(){ return intel; }

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