#include "World.h"

int main(){
	srand(time(NULL));

	OrkRoom a;

	a.printRoom();

	Character* c = new Character();

	World b;

	//b.printMap();

	b.placeChar(c);
	b.printMap();

	while (true){

		b.movePlayerChar(_getch());
		b.updateMovement();
		b.printMap();

	}

	return 0;
}