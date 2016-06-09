#include "Food.h"
#include <iomanip>

Food::Food(const Food &obj) : Item(obj){
	stackable = true; 
	useable = true;
	this->stack = obj.stack;
	this->turns = obj.turns;
	this->totWeight = obj.totWeight;
}

void Food::setStack(int s){
	if (s < 0){
		stack = 0;
		return;
	}
	stack = s;
}

void Food::addStacks(Item* i){
	addStack(i->getStack());
	delete i;
}

int Food::getStack(){
	return stack;
}

void Food::examine(){
	cout << "(" << stack << ") ";
	cout << getName() << endl;
	getSymbol()->printSymbol();
	cout << endl;
	cout << "Weight: " << setprecision(2) << fixed << totWeight << endl;
	cout << "Nourishment: " << turns << " turns." << endl;
}

Item* Food::clone(){
	return new Food(*this);
}

void Food::eat(Character* c){
	if (!c->getFoodSickness()){
		stack--;
		RegenerationModifier* temp = new RegenerationModifier(turns, .15, c);
		if (stack <= 0)
			delete this;

		c->addMod(temp);
		c->setFoodSickness(temp->getTurns());

		cout << "You have consumed the food." << endl;
	}
	else cout << "Too full to eat! " << endl;
}

Bread::Bread(Inventory* p, int stack) : Food(p){
	setName("Bread");
	setWeight(0.5);
	setSymbol(new Symbol(';', 6));
	setItemID(getNextID());
	setStack(stack);
	totWeight = getWeight()*stack;
	turns = 300;
}