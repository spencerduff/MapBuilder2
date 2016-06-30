#include "PlayerCharacter.h"

const string PlayerCharacter::races[6]{ "Ork", "Mahirim", "Human", "Elf", "Dwarf", "Alfar" };

PlayerCharacter::PlayerCharacter(Map* m) : Character(m){
	system("CLS");

	character = new Symbol('@', 6);

	namePrompt();
	racePrompt();

	spellbook->learn(new HealSelf(this));
	spellbook->learn(new Fireball(this));
	spellbook->learn(new Stormblast(this));

	ai = NULL;

	backpack->inventory.push_back(new Leafblade(backpack));
	backpack->inventory.push_back(new DragonChest(backpack));
	backpack->inventory.push_back(new Bile(backpack));
	backpack->inventory.push_back(new Cinder(backpack));
	backpack->inventory.push_back(new Darktaint(backpack));
	backpack->inventory.push_back(new Numen(backpack));
	backpack->inventory.push_back(new TrollStaff(backpack));
	backpack->inventory.push_back(new Bread(backpack));
	backpack->consolidateStackables();

	openingScreen();
}

void PlayerCharacter::namePrompt(){
	cout << "What would you like to name your Character?" << endl;
	cin >> name;
}

void PlayerCharacter::racePrompt(){
	while (true){
		cout << "Which race would you like to be?" << endl;
		cin.clear();
		cout << "(O)rk, (M)ahirim, (H)uman, (E)lf, (D)warf, or (A)lfar?" << endl;

		char racePick;
		cin >> racePick;

		if (racePick != 'O' && racePick != 'M' && racePick != 'H' && racePick != 'E' && racePick != 'D' && racePick != 'A' &&
			racePick != 'o' && racePick != 'm' && racePick != 'h' && racePick != 'e' && racePick != 'd' && racePick != 'a'){
			cout << "Please pick a valid race." << endl;
			continue;
		}
		racePick = tolower(racePick);

		switch (racePick){
		case 'o':
			racialAlignment = OrkMahirim;
			race = Ork;
			break;

		case 'm':
			racialAlignment = OrkMahirim;
			race = Mahirim;
			break;

		case 'h':
			racialAlignment = HumanDwarfMirdain;
			race = Human;
			break;

		case 'e':
			racialAlignment = HumanDwarfMirdain;
			race = Elf;
			break;

		case 'd':
			racialAlignment = HumanDwarfMirdain;
			race = Dwarf;
			break;

		case 'a':
			racialAlignment = GoodAlfar;
			race = Alfar;
			break;

		}
		return;
	}
}

void PlayerCharacter::openingScreen(){
	cout << endl << endl;
	cout << "Welcome to the world of Agon!\n";
	cout << "It is a land full of conflict and treasure, as well as many powers to be discovered and learned.\n";

	cout << "You start your adventure as ";
	if (race == Ork || race == Elf || race == Alfar)
		cout << "an ";
	else cout << "a ";
	
	cout << races[race] << ".\n";

	cout << "Your name is " << name << ".\n";

	cout << "You have some items in your backpack, and being the studious one you are, some knowledge of a few spells.\n";

	cout << "The help menu can be accessed by pressing ?. Good luck to you, " << name << "!" << endl;

	cout << "Press any key to begin the adventure. ";

	_getch();
}