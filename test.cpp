#include "World.h"
#include "SaveState.h"
#include "PlayerCharacter.h"

bool isGUI(char a);

int main(){

	unsigned int seed = (unsigned int)time(NULL);

	srand(seed);

	cout << "Would you like to start a new game?" << endl;
	char answer = 'n';
	cin >> answer;

	World* b;

	if (answer == 'y' || answer == 'Y' || true){

		cout << "Creating World... " << endl;
		
		b = new World();

		Character* c = new PlayerCharacter(b->getCurrMap());


		b->placeChar(c);
		b->placeRandomCrafting(new Thaumaturgy());

	}
	else {
		b = &World(SaveState::load());

	}

	system("CLS");
	b->printMap();


	char input;

	while (true){
		input = _getch();
		if (input == '?')
			HelpMenu a;
		b->movePlayerChar(input);
		if (input == 27) //ESC
			SaveState::save(b);
		if (isGUI(input)){
			continue;
		}
		b->updateMovement();
		//b->printMap();
	}

	return 0;
}

bool isGUI(char a){
	if (a == 'p' || a == 'i' || a == 'e' || a == 'I' || a == 's' || a == 'S' || a == '?')
		return true;
	else return false;
}

//regex to count lines in project: ^(?!(\s*\*))(?!(\s*\-\-\>))(?!(\s*\<\!\-\-))(?!(\s*\n))(?!(\s*\*\/))(?!(\s*\/\*))(?!(\s*\/\/\/))(?!(\s*\/\/))(?!(\s*\}))(?!(\s*\{))(?!(\s(using))).*$
