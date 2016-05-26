#include "Land.h"

class World{

public:
	World();

	void placeChar(Character* c, char side = '<'){ currLand->placeChar(c, side); }
	void placeRandomChar(Character* c){ currLand->placeRandomChar(c); }
	void printMap(){ currLand->printMap(); }
	//Need this function to return a string to print out after the map refreshes but before next input
	void movePlayerChar(char c);
	void updateMovement(){ currLand->updateMovement(); }
	void moveLands();

private:
	string name;
	Land ***lands;
	int xLandPos, yLandPos;
	Land * currLand;

};