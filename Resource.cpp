#include "Resource.h"

void Resource::setStack(int s){
	if (s < 0){
		stack = 0;
		return;
	}
	stack = s;
}

Iron::Iron(Inventory* p, int stack) : Resource(p){
	setName("Iron");
	setWeight(0.5);
	setSymbol(new Symbol('*', 0, 0, 8, 0));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(iron);
}

Wood::Wood(Inventory* p, int stack) : Resource(p){
	setName("Wood");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, 0, 2, 0));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(wood);
}

Cloth::Cloth(Inventory* p, int stack) : Resource(p){
	setName("Cloth");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, 0, 7, 0));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(cloth);
}

Leather::Leather(Inventory* p, int stack) : Resource(p){
	setName("Leather");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, 0, 14, 0));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(leather);
}

Selentine::Selentine(Inventory* p, int stack) : Resource(p){
	setName("Selentine");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, 0, 7, 0));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(selentine);
}

Veilron::Veilron(Inventory* p, int stack) : Resource(p){
	setName("Veilron");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, 0, 0, 7));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(veilron);
}

Neithal::Neithal(Inventory* p, int stack) : Resource(p){
	setName("Neithal");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, 0, 1, 0));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(neithal);
}

Leenspar::Leenspar(Inventory* p, int stack) : Resource(p){
	setName("Leenspar");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, 0, 4, 0));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(leenspar);
}

Theyril::Theyril(Inventory* p, int stack) : Resource(p){
	setName("Theyril");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, 0, 15, 0));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(theyril);
}