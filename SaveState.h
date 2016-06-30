#ifndef SAVESTATE_H
#define SAVESTATE_H

#include "World.h"
#include <fstream>

class SaveState{
public:
	// Helper to call the meaty save function
	static void save(World* a);
	// Helper to call the meaty load function
	static World load();


private:
	// Writes a binary file with the name of 'name'
	static void save(string name, World* a);
	// Reads a binary file with the name of 'name'
	static World load(string name);


};


#endif