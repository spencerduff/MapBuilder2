#ifndef ENCHANTING_H
#define ENCHANTING_H

#include "Armor.h"
#include "Weapon.h"

enum Material{bile, blood, bone, cinder, claw, corpseflesh, darktaint, eye, greenleaf, heart, hoarfrost, horn, lifeforce, quartz, quintessence, shadowcrest, sparkstone, stormrune, tooth, venomsac};
enum Catalyst{ichor, nith, numen};

// Enchanting Mats. They are a type of Item that are used in enchanting.
class EnchantingMat : public Item{
public:
	// Takes a material type and a quality
	EnchantingMat(Material m, float q, int istack, Inventory* p);

	// Adds an int to the stack.
	void addStack(int a){ stack += a; totWeight = stack*getWeight(); }

	// Getters
	Material getMat(){ return material; }
	float getQuality(){ return quality; }
	int getStack() override;

	// Decrements the stack by one. Called when used in an enchant. Deletes item when 0 stack left.
	void decrementStack();
	// Adds two stacks together. Called when ConsolidateStackables() in an Inventory
	void addStacks(Item* i) override;

	// Overridden examine function. Prints out details about the Mat.
	void examine() override;

	// Adds the item to the Mats slot in the enchanting table.
	void addToEnchantingTable(Thaumaturgy *t) override;

protected:
	float totWeight;
	Material material;
	float quality;
	int stack;
};

// Enchanting Catalysts. They are a type of Item that are used in enchanting.
class EnchantingCatalyst : public Item{
public:
	// Needs to pass up the inventory it is in.
	EnchantingCatalyst(Catalyst c, int istack, Inventory* p);

	// Add to the stack a number and update weight.
	void addStack(int a){ stack += a; totWeight = stack*getWeight(); }

	// Getters
	Catalyst getCatalyst(){ return catalyst; }
	int getStack() override;

	// Decrement stack when enchant happens. When 0, the Item is deleted.
	void decrementStack();

	// Add two stacks of the same Mat together. Called in consolidateStacks()
	void addStacks(Item* i) override;

	// Overridden function to output details of the Catalyst
	void examine() override;

	// Adds the Item to the EnchantingCatalyst slot on an enchanting table.
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