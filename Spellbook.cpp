#include "Spellbook.h"
#include <iomanip>

char spellSpace[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

Spellbook::Spellbook(Character* c){
	owner = c;
}

Spellbook::~Spellbook(){
	for (auto i = spellList.begin(); i != spellList.end(); ++i){
		delete (*i);
		*i = nullptr;
	}
	spellList.clear();
}

void Spellbook::learn(Spell* s){
	spellList.push_back(s);
}

void Spellbook::printSpellbook(){
	cout << "Known Spells: " << endl;
	for (unsigned int i = 0; i < spellList.size(); i++){
		cout << i << ": " << spellList[i]->getName() << " level: " << setprecision(2) << fixed << spellList[i]->getLevel() << "." << endl;
	}
}

int Spellbook::parsePosInSpellbook(char input){
	if (input == 'Q') return -1;
	int pos = 0;
	if (input >= 97 && input <= 122)
		pos = (input - 87);
	else if (input >= 48 && input <= 57)
		pos = (input - 48);
	else return -1;
	return pos;
}