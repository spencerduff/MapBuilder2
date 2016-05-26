#include "World.h"

bool isGUI(char a);

int main(){
	srand((unsigned int)time(NULL));

	Character* c = new Character();
	Character* g = new Goblin();

	World b;

	//b.printMap();

	b.placeChar(c);
	b.placeRandomChar(g);
	b.printMap();
	char input;

	while (true){
		input = _getch();	
		string output1 = b.movePlayerChar(input);
		if (isGUI(input)){
			cout << output1;
			continue;
		}
		string output2 = b.updateMovement();
		b.printMap();
		cout << output1 << output2;
	}

	return 0;
}

bool isGUI(char a){
	if (a == 'p' || a == 'i' || a == 'e' || a == 'I' || a == 's' || a == 'S')
		return true;
	else return false;
}

//regex to count lines in solution: ^(?!(\s*\*))(?!(\s*\-\-\>))(?!(\s*\<\!\-\-))(?!(\s*\n))(?!(\s*\*\/))(?!(\s*\/\*))(?!(\s*\/\/\/))(?!(\s*\/\/))(?!(\s*\}))(?!(\s*\{))(?!(\s(using))).*$
