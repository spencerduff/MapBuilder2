#include "World.h"

bool isGUI(char a);

int main(){
	srand((unsigned int)time(NULL));

	char* music = "C:\\Users\\Spencer\\Music\\Real_Music\\Darklight\\Darklight_-_Theatrum_October_full_album.mp3";

//	system(music);

	cout << "Creating World... " << endl;
	World b;



	Character* c = new Character(b.getCurrMap());


	b.placeChar(c);
	b.placeRandomChar(new Goblin(b.getCurrMap()));
	b.placeRandomChar(new Goblin(b.getCurrMap()));
	b.placeRandomCrafting(new Thaumaturgy());

	system("CLS");
	b.printMap();
	char input;

	while (true){
		input = _getch();	
		b.movePlayerChar(input);
		if (isGUI(input)){
			continue;
		}
		b.updateMovement();
		//b.printMap();
	}

	return 0;
}

bool isGUI(char a){
	if (a == 'p' || a == 'i' || a == 'e' || a == 'I' || a == 's' || a == 'S')
		return true;
	else return false;
}

//regex to count lines in project: ^(?!(\s*\*))(?!(\s*\-\-\>))(?!(\s*\<\!\-\-))(?!(\s*\n))(?!(\s*\*\/))(?!(\s*\/\*))(?!(\s*\/\/\/))(?!(\s*\/\/))(?!(\s*\}))(?!(\s*\{))(?!(\s(using))).*$
