#ifndef FOOD_H
#define FOOD_H

#include "Item.h"
#include "Modifiers.h"

class Food : public Item{
public:
	Food(Inventory* p) : Item(p){ stackable = true; useable = true; }

	Food(const Food &obj);
	
	// Add a number to the stack.
	void addStack(int a){ stack += a; totWeight = stack*getWeight(); }
	// Add the stacks of two Foods
	void addStacks(Item* i) override;
	// Prints details about the Food to the screen.
	void examine() override;

	void use(Character* c) override { eat(c); }

	// Getter
	int getStack() override;

	virtual Item* clone() override;

protected:
	int turns;
	float totWeight;
	int stack;

	// Setter
	void setStack(int s);

private:
	void eat(Character* c);

};

class Bread : public Food{
public:
	Bread(Inventory* p, int stack = 1);
};



#endif