#include "Land.h"

class World{
private:
	string name;
	Land ***lands;
	int xLandPos, yLandPos;
	Land * currLand;

public:
	World();

	void placeChar(Character* c, char side = '<'){ currLand->placeChar(c, side); }
	void printMap(){ currLand->printMap(); }
	void movePlayerChar(char c) { currLand->movePlayerChar(c); }
	void updateMovement(){ currLand->updateMovement(); }

};