#include "SaveState.h"

void SaveState::save(World* a){
	cout << "What would you like to name your save file? " << endl;
	string name;
	cin >> name;
	name.append(".txt");
	save(name, a);
}

void SaveState::save(string name, World* a){

	ofstream ofs(name, ios::binary | ofstream::trunc);

	ofs.clear();

	
	// figure out what and how to save.


	ofs.close();
}

World SaveState::load(){
	cout << "Name of file to load?" << endl;
	string name;
	cin >> name;
	name.append(".txt");

	return load(name);
}

World SaveState::load(string name){

	// figure out what and how to read

	return World();

}