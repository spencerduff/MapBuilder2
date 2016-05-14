#include "World.h"

int main(){
	srand((unsigned int)time(NULL));

	OrkRoom a;

	a.printRoom();

	Character* c = new Character();

	World b;

	//b.printMap();

	b.placeChar(c);
	b.printMap();
	char input;

	while (true){

		input = _getch();
		b.movePlayerChar(input);
		if (input == 'p')
			continue;
		b.updateMovement();
		b.printMap();

	}

	return 0;
}