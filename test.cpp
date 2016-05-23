#include "World.h"

bool isGUI(char a);

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
		if (isGUI(input))
			continue;
		b.updateMovement();
		b.printMap();

	}

	return 0;
}

bool isGUI(char a){
	if (a == 'p' || a == 'i' || a == 'e' || a == 'I')
		return true;
	else return false;
}