#ifndef LAND_H
#define LAND_H

#include "Map.h"


// Holds a double pointer of Maps
// Maps can be revisited after you move off of them
// Go far enough in any direction to move to a new Land that will be held in a World
class Land{
public:
	Map*** maps;
	Map* currMap;
	Land();
	Land(string l);
	~Land();

	// Used to move the Player Character between maps.
	void moveMaps();
	// Passes movement updates to the currMap where they are handled.
	void updateMovement(){ currMap->updateMovement(); }
	// Moves all the Characters. Refreshes needed tiles (projectiles).
	void movePlayerChar(char c);
	// Prints the map and some flavor text
	void printMap(){ 
		cout << "You are in " << land << " You are at [" << xMapPos << "] [" << yMapPos << "].";
		if (xMapPos == 2 && yMapPos == 2)
			cout << " This is the starting area for this land.";
		cout << endl;
		currMap->printMap();
	}
	// Calls a function to place the Character on the side of the currMap
	void placeChar(Character* c, char side = '<'){ currMap->placeChar(c, side); }
	// Calls a function to randomly place the Character on the currMap
	void placeRandomChar(Character* c){ currMap->placeRandomChar(c); }
	// Calls a function to randomly place a crafting table on the currMap.
	void placeRandomCrafting(CraftingStation* c){ currMap->placeRandomCrafting(c); }
	
	// Getters
	int getXMapPos(){ return xMapPos; }
	int getYMapPos(){ return yMapPos; }
	int getLandSize(){ return landSize; }
	string getLand(){ return land; }
	// Setters
	void setXMapPos(int x){ xMapPos = x; }
	void setYMapPos(int y){ yMapPos = y; }

protected:
	int landSize;
	int xMapPos, yMapPos;
	string land;

};

class OrkLands : public Land{

public:
	OrkLands();

};

class HumanLands : public Land{

public:
	HumanLands();

};

#endif