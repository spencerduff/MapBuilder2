#include "World.h"

int main(){
	srand((unsigned int)time(NULL));

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
		if (input == 'i')
			continue;
		b.updateMovement();
		b.printMap();

	}

	return 0;
}