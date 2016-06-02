#ifndef ENCHANTING_H
#define ENCHANTING_H

#include "Armor.h"
#include "Weapon.h"

enum Material{bile, blood, bone, cinder, claw, corpseflesh, darktaint, eye, greenleaf, heart, hoarfrost, horn, lifeforce, quartz, quintessence, shadowcrest, sparkstone, stormrune, tooth, venomsac};
enum Catalyst{ichor, nith, numen};

class EnchantingMat : public Item{
public:
	//Takes a material type and a quality
	EnchantingMat(Material m, float q, int istack, Inventory* p);

	void addStack(int a){ stack += a; totWeight = stack*getWeight(); }

	Material getMat(){ return material; }
	float getQuality(){ return quality; }
	int getStack() override;

	void decrementStack();
	void addStacks(Item* i) override;

	void examine() override;

	void addToEnchantingTable(Thaumaturgy *t) override;

protected:
	float totWeight;
	Material material;
	float quality;
	int stack;
};

class EnchantingCatalyst : public Item{
public:
	EnchantingCatalyst(Catalyst c, int istack, Inventory* p);

	void addStack(int a){ stack += a; totWeight = stack*getWeight(); }

	Catalyst getCatalyst(){ return catalyst; }
	void decrementStack();

	void addStacks(Item* i) override;
	int getStack() override;

	void examine() override;

	void addToEnchantingTable(Thaumaturgy *t) override;

protected:
	float totWeight;
	Catalyst catalyst;
	int stack;
};

class Bile : public EnchantingMat{
public:
	Bile(Inventory* p, float iquality = 1.0, int istack = 1);
};

class Cinder : public EnchantingMat{
public:
	Cinder(Inventory* p, float iquality = 1.0, int istack = 1);
};

class Darktaint : public EnchantingMat{
public:
	Darktaint(Inventory* p, float iquality = 1.0, int istack = 1);
};

class Numen : public EnchantingCatalyst{
public:
	Numen(Inventory* p, int istack = 1);
};

#endif