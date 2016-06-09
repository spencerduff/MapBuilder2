#include "Item.h"


enum ResourceType{ iron, wood, cloth, leather, selentine, veilron, neithal, leenspar, theyril };

class Resource : public Item{
public:
	// Add a number to the stack.
	void addStack(int a){ stack += a; totWeight = stack*getWeight(); }
	// Add the stacks of two Resources
	void addStacks(Item* i) override;

	// Getter
	int getStack() override;

	// Prints details about the Resource to the screen.
	void examine() override;

	virtual Item* clone() override;

protected:
	Resource(Inventory* p) : Item(p) { stackable = true; }
	// Setters
	void setStack(int s);
	void setResourceType(ResourceType iType){ type = iType; }
	float totWeight;

private:
	ResourceType type;
	int stack;
};

class Iron : public Resource{
public:
	Iron(Inventory* p, int stack = 1);
};

class Wood : public Resource{
public:
	Wood(Inventory* p, int stack = 1);
};

class Cloth : public Resource{
public:
	Cloth(Inventory* p, int stack = 1);
};

class Leather : public Resource{
public:
	Leather(Inventory* p, int stack = 1);
};

class Selentine : public Resource{
public:
	Selentine(Inventory* p, int stack = 1);
};

class Veilron : public Resource{
public:
	Veilron(Inventory* p, int stack = 1);
};

class Neithal : public Resource{
public:
	Neithal(Inventory* p, int stack = 1);
};

class Leenspar : public Resource{
public:
	Leenspar(Inventory* p, int stack = 1);
};

class Theyril : public Resource{
public:
	Theyril(Inventory* p, int stack = 1);
};