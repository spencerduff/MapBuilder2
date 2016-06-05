#ifndef ENCHANTS_H
#define ENCHANTS_H

#include "EnchantingMats.h"

enum EnchantType{ keen };
enum ItemType{ weapons, apparel, general, mageStaves };

// Enchants that are possible in the game. They each take 3 different enchanting mats and a catalyst.
class Enchant{
public:
	// Overridden function that allows each specific enchant to decide how it enchants.
	virtual void enchant(EnchantingMat* m1, EnchantingMat* m2, EnchantingMat* m3, EnchantingCatalyst* c, Item* i) = 0;
	virtual void enchant(Weapon* w) = 0;

	// Sets the quality based on 3 mat qualities
	float setQuality(float mq1, float mq2, float mq3);

	// Getters
	Material getReq1(){ return requirement1; }
	Material getReq2(){ return requirement2; }
	Material getReq3(){ return requirement3; }
	Catalyst getCata(){ return requiredCatalyst; }
	string getName(){ return name; }

protected:
	EnchantType enchantType;
	ItemType itemType;
	Material requirement1, requirement2, requirement3;
	Catalyst requiredCatalyst;
	string name;
};

// Type of enchant. Adds damage to a melee weapon.
class Keen : public Enchant{
public:
	// Constructs a keen. Quality and DmgMod are decided by the enchant.
	Keen();

	// Applies a keen to the Item using polymorphism to figure out which type of Item it is.
	void enchant(EnchantingMat* m1, EnchantingMat* m2, EnchantingMat* m3, EnchantingCatalyst* c, Item* i) override;
	// If it is a Weapon, it will call this enchant, which will apply the keen to it.
	void enchant(Weapon* w) override;

	// Getter
	float getDmgMod(){ return dmgModifier; }

private:
	float quality;
	float dmgModifier;
};

#endif