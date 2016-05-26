#include "CharacterStats.h"
#include <iostream>
#include <iomanip>

using namespace std;

CharacterStats::CharacterStats(){
	currhp = hp = 200;
	currmana = mana = 200;
	currstam = stam = 200;

	alignment = 10;

	str = vit = dex = quick = intel = wis = 20;

	encumbrance = 0;

	arrowProt = bludgeoningProt = piercingProt = slashingProt = 0;

	acidProt = arcaneProt = coldProt = fireProt = holyProt = impactProt = lightningProt = unholyProt = 0;

	maledictionProt = mentalProt = inflictionProt = 0;

}

CharacterStats::CharacterStats(float iHP, float iStam, float iMana, float iStr, float iVit, float iDex, float iQuick, float iIntel, float iWis){
	currhp = hp = iHP;
	currmana = mana = iMana;
	currstam = stam = iStam;

	alignment = 10;

	str = iStr;
	vit = iVit;
	dex = iDex;
	quick = iQuick;
	intel = iIntel;
	wis = iWis;

	encumbrance = 0;

	arrowProt = bludgeoningProt = piercingProt = slashingProt = 0;

	acidProt = arcaneProt = coldProt = fireProt = holyProt = impactProt = lightningProt = unholyProt = 0;

	maledictionProt = mentalProt = inflictionProt = 0;
}

CharacterStats::~CharacterStats(){

}

void CharacterStats::resetProts(){
	arrowProt = bludgeoningProt = piercingProt = slashingProt = 0;

	acidProt = arcaneProt = coldProt = fireProt = holyProt = impactProt = lightningProt = unholyProt = 0;

	maledictionProt = mentalProt = inflictionProt = 0;
}

void CharacterStats::resetEncumbrance(){
	encumbrance = 0;
}

void CharacterStats::addProts(Armor *a){
	if (a == NULL)
		return;
	if (a->equipped)
	encumbrance += a->getEncumbrance();

	arrowProt += a->getProts().protPiercing;
	bludgeoningProt += a->getProts().protBludgeoning;
	piercingProt += a->getProts().protPiercing;
	slashingProt += a->getProts().protSlashing;

	acidProt += a->getProts().protAcid;
	arcaneProt += a->getProts().protArcane;
	coldProt += a->getProts().protCold;
	fireProt += a->getProts().protFire;
	holyProt += a->getProts().protHoly;
	impactProt += a->getProts().protImpact;
	lightningProt += a->getProts().protLightning;
	unholyProt += a->getProts().protUnholy;
}

void CharacterStats::printStats(){
	cout << "Status..." << endl;
	cout << "Health: " << setprecision(2) << fixed << currhp << "/" << setprecision(2) << fixed << hp << endl;
	cout << "Stamina: " << setprecision(2) << fixed << currstam << "/" << setprecision(2) << fixed << stam << endl;
	cout << "Mana: " << setprecision(2) << fixed << currmana << "/" << setprecision(2) << fixed << mana << endl;
	cout << "Alignment: " << alignment << endl << endl;

}

void CharacterStats::printFullStats(){
	printStats();

	cout << setw(30) << "Base Attributes..." << endl;
	cout << setw(15) << "Strength: " << setprecision(2) << fixed << str << setw(15) << "Vitality: " << setprecision(2) << fixed << vit << endl;
	cout << setw(15) << "Dexterity: " << setprecision(2) << fixed << dex << setw(15) << "Quickness: " << setprecision(2) << fixed << quick << endl;
	cout << setw(15) << "Intelligence: " << setprecision(2) << fixed << intel << setw(15) << "Wisdom: " << setprecision(2) << fixed << wis << endl << endl;

	cout << "Encumbrance: " << encumbrance << endl << endl;

	cout << "Protections..." << endl;

	cout << "Arrow: " << setprecision(2) << fixed << arrowProt << endl;
	cout << "Bludgeoning: " << setprecision(2) << fixed << bludgeoningProt << endl;
	cout << "Piercing: " << setprecision(2) << fixed << piercingProt << endl;
	cout << "Slashing: " << setprecision(2) << fixed << slashingProt << endl << endl;

	cout << "Acid: " << setprecision(2) << fixed << acidProt << endl;
	cout << "Arcane: " << setprecision(2) << fixed << arcaneProt << endl;
	cout << "Cold: " << setprecision(2) << fixed << coldProt << endl;
	cout << "Fire: " << setprecision(2) << fixed << fireProt << endl;
	cout << "Holy: " << setprecision(2) << fixed << holyProt << endl;
	cout << "Impact: " << setprecision(2) << fixed << impactProt << endl;
	cout << "Lightning: " << setprecision(2) << fixed << lightningProt << endl;
	cout << "Unholy: " << setprecision(2) << fixed << unholyProt << endl << endl;

	cout << "Malediction: " << setprecision(2) << fixed << maledictionProt << endl;
	cout << "Mental: " << setprecision(2) << fixed << mentalProt << endl;
	cout << "Infliction: " << setprecision(2) << fixed << inflictionProt << endl << endl;

}

void CharacterStats::damage(Damage amount){
	currhp -= amount.damage;

	switch (amount.damageType){
	case bludgeoning:
		currstam -= (amount.damage * 0.4);
		break;
	case slashing:
	case piercing:
	case arrow:
		currstam -= (amount.damage * 0.2);
		break;
	}

}

void CharacterStats::setHP(float newHP){
	if (newHP < 5)
		return;
	hp = newHP;
	if (currhp > hp)
		currhp = hp;
}
void CharacterStats::setStam(float newStam){
	if (newStam < 5)
		return;
	stam = newStam;
	if (currstam > stam)
		currstam = stam;
}
void CharacterStats::setMana(float newMana){
	if (newMana < 5)
		return;
	mana = newMana;
	if (currmana > mana)
		currmana = mana;
}
void CharacterStats::setStr(float newStr){
	if (newStr > 100){
		cout << "Too high to set Attribute. " << endl;
		return;
	}
	if (newStr < 4)
		return;
	str = newStr;
}
void CharacterStats::setVit(float newVit){
	if (newVit > 100){
		cout << "Too high to set Attribute. " << endl;
		return;
	}
	if (newVit < 4)
		return;
	vit = newVit;
}
void CharacterStats::setDex(float newDex){
	if (newDex > 100){
		cout << "Too high to set Attribute. " << endl;
		return;
	}
	if (newDex < 4)
		return;
	dex = newDex;
}
void CharacterStats::setQuick(float newQuick){
	if (newQuick > 100){
		cout << "Too high to set Attribute. " << endl;
		return;
	}
	if (newQuick < 4)
		return;
	quick = newQuick;
}
void CharacterStats::setIntel(float newIntel){
	if (newIntel > 100){
		cout << "Too high to set Attribute. " << endl;
		return;
	}
	if (newIntel < 4)
		return;
	intel = newIntel;
}
void CharacterStats::setWis(float newWis){
	if (newWis > 100){
		cout << "Too high to set Attribute. " << endl;
		return;
	}
	if (newWis < 4)
		return;
	wis = newWis;
}