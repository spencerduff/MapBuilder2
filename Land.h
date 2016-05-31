#include "Map.h"


//Should hold a double pointer of Maps
//Maps can be revisited after you move off of them
//Go far enough in any direction to move to a new Land that will be held in a World

class Land{
public:
	Map*** maps;
	Map* currMap;
	Land();
	Land(string l);
	void moveMaps();
	string updateMovement(){ return currMap->updateMovement(); }
	string movePlayerChar(char c);
	//Prints the map and some flavor text
	void printMap(){ 
		system("CLS");
		cout << "You are in " << land << " You are at [" << xMapPos << "] [" << yMapPos << "].";
		if (xMapPos == 2 && yMapPos == 2)
			cout << " This is the starting area for this land.";
		cout << endl;
		currMap->printMap();
	}
	void placeChar(Character* c, char side = '<'){ currMap->placeChar(c, side); }
	void placeRandomChar(Character* c){ currMap->placeRandomChar(c); }
	void placeRandomCrafting(CraftingStation* c){ currMap->placeRandomCrafting(c); }
	
	int getXMapPos(){ return xMapPos; }
	int getYMapPos(){ return yMapPos; }
	int getLandSize(){ return landSize; }
	string getLand(){ return land; }
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