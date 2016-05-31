#include "Land.h"

class World{

public:
	World();

	void placeChar(Character* c, char side = '<'){ currLand->placeChar(c, side); }
	void placeRandomChar(Character* c){ currLand->placeRandomChar(c); }
	void placeRandomCrafting(CraftingStation* c){ currLand->placeRandomCrafting(c); }
	void printMap(){ currLand->printMap(); }
	//Need this function to return a string to print out after the map refreshes but before next input
	string movePlayerChar(char c);
	string updateMovement(){ return currLand->updateMovement(); }
	string moveLands();
	Map* getCurrMap(){ return currLand->currMap; }

private:
	string name;
	Land ***lands;
	int xLandPos, yLandPos;
	Land *currLand;

};