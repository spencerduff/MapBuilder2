#include "Resource.h"
#include <iomanip>

void Resource::setStack(int s){
	if (s < 0){
		stack = 0;
		return;
	}
	stack = s;
}

void Resource::addStacks(Item* i){
	addStack(i->getStack());
	delete i;
}

int Resource::getStack(){
	return stack;
}

void Resource::examine(){
	cout << "(" << stack << ") ";
	cout << getName() << endl;
	getSymbol()->printSymbol();
	cout << endl;
	cout << "Weight: " << setprecision(2) << fixed << totWeight << endl;
}

Item* Resource::clone(){
	return new Resource(*this);
}

Iron::Iron(Inventory* p, int stack) : Resource(p){
	setName("Iron");
	setWeight(0.5);
	setSymbol(new Symbol('*', 8));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(iron);
}

Wood::Wood(Inventory* p, int stack) : Resource(p){
	setName("Wood");
	setWeight(0.1);
	setSymbol(new Symbol('*', 6));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(wood);
}

Cloth::Cloth(Inventory* p, int stack) : Resource(p){
	setName("Cloth");
	setWeight(0.1);
	setSymbol(new Symbol('*', 7));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(cloth);
}

Leather::Leather(Inventory* p, int stack) : Resource(p){
	setName("Leather");
	setWeight(0.1);
	setSymbol(new Symbol('*', 14));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(leather);
}

Selentine::Selentine(Inventory* p, int stack) : Resource(p){
	setName("Selentine");
	setWeight(0.1);
	setSymbol(new Symbol('*', 7));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(selentine);
}

Veilron::Veilron(Inventory* p, int stack) : Resource(p){
	setName("Veilron");
	setWeight(0.1);
	setSymbol(new Symbol('*', 0, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(veilron);
}

Neithal::Neithal(Inventory* p, int stack) : Resource(p){
	setName("Neithal");
	setWeight(0.1);
	setSymbol(new Symbol('*', 1));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(neithal);
}

Leenspar::Leenspar(Inventory* p, int stack) : Resource(p){
	setName("Leenspar");
	setWeight(0.1);
	setSymbol(new Symbol('*', 4));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(leenspar);
}

Theyril::Theyril(Inventory* p, int stack) : Resource(p){
	setName("Theyril");
	setWeight(0.1);
	setSymbol(new Symbol('*', 15));
	setItemID(getNextID());
	setStack(stack);
	setResourceType(theyril);
}