#ifndef ENCHANTS_H
#define ENCHANTS_H

#include "EnchantingMats.h"

enum EnchantType{ keen };
enum ItemType{ weapons, apparel, general, mageStaves };

class Enchant{
public:
	virtual void enchant(EnchantingMat* m1, EnchantingMat* m2, EnchantingMat* m3, EnchantingCatalyst* c, Item* i) = 0;
	virtual void enchant(Weapon* w) = 0;

	float setQuality(float mq1, float mq2, float mq3);

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

class Keen : public Enchant{
public:
	Keen();

	void enchant(EnchantingMat* m1, EnchantingMat* m2, EnchantingMat* m3, EnchantingCatalyst* c, Item* i) override;
	void enchant(Weapon* w) override;
	float getDmgMod(){ return dmgModifier; }

private:
	float quality;
	float dmgModifier;
};

#endif