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

	Material getMat(){ return material; }
	float getQuality(){ return quality; }
	void decrementStack();

	void addToEnchantingTable(Thaumaturgy *t) override;

protected:
	Material material;
	float quality;
	int stack;
};

class EnchantingCatalyst : public Item{
public:
	EnchantingCatalyst(Catalyst c, int istack, Inventory* p);

	Catalyst getCatalyst(){ return catalyst; }
	void decrementStack();

	void addToEnchantingTable(Thaumaturgy *t) override;

protected:
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