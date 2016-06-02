#include "Item.h"


enum ResourceType{ iron, wood, cloth, leather, selentine, veilron, neithal, leenspar, theyril };

class Resource : public Item{
public:
	void addStack(int a){ stack += a; totWeight = stack*getWeight(); }
	void addStacks(Item* i) override;
	int getStack() override;
	void examine() override;

protected:
	Resource(Inventory* p) : Item(p) { stackable = true; }
	void setStack(int s);
	void setResourceType(ResourceType iType){ type = iType; }

private:
	float totWeight;
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