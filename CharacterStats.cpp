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

	encumberance = 0;

	arrow = bludgeoning = piercing = slashing = 0;

	acid = arcane = cold = fire = holy = impact = lightning = unholy = 0;

	malediction = mental = infliction = 0;

}

void CharacterStats::resetProts(){
	arrow = bludgeoning = piercing = slashing = 0;

	acid = arcane = cold = fire = holy = impact = lightning = unholy = 0;

	malediction = mental = infliction = 0;
}

void CharacterStats::addProts(Armor *a){
	if (a == NULL)
		return;
	encumberance += a->getEncumberance();

	arrow += a->getProts().protPiercing;
	bludgeoning += a->getProts().protBludgeoning;
	piercing += a->getProts().protPiercing;
	slashing += a->getProts().protSlashing;

	acid += a->getProts().protAcid;
	arcane += a->getProts().protArcane;
	cold += a->getProts().protCold;
	fire += a->getProts().protFire;
	holy += a->getProts().protHoly;
	impact += a->getProts().protImpact;
	lightning += a->getProts().protLightning;
	unholy += a->getProts().protUnholy;
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

	cout << "Encumberance: " << encumberance << endl << endl;

	cout << "Protections..." << endl;

	cout << "Arrow: " << setprecision(2) << fixed << arrow << endl;
	cout << "Bludgeoning: " << setprecision(2) << fixed << bludgeoning << endl;
	cout << "Piercing: " << setprecision(2) << fixed << piercing << endl;
	cout << "Slashing: " << setprecision(2) << fixed << slashing << endl << endl;

	cout << "Acid: " << setprecision(2) << fixed << acid << endl;
	cout << "Arcane: " << setprecision(2) << fixed << arcane << endl;
	cout << "Cold: " << setprecision(2) << fixed << cold << endl;
	cout << "Fire: " << setprecision(2) << fixed << fire << endl;
	cout << "Holy: " << setprecision(2) << fixed << holy << endl;
	cout << "Impact: " << setprecision(2) << fixed << impact << endl;
	cout << "Lightning: " << setprecision(2) << fixed << lightning << endl;
	cout << "Unholy: " << setprecision(2) << fixed << unholy << endl << endl;

	cout << "Malediction: " << setprecision(2) << fixed << malediction << endl;
	cout << "Mental: " << setprecision(2) << fixed << mental << endl;
	cout << "Infliction: " << setprecision(2) << fixed << infliction << endl << endl;

}
