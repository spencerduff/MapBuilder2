#include "Land.h"

class World{

public:
	World();

	// Places the Character to the side of a map.
	void placeChar(Character* c, char side = '<'){ currLand->placeChar(c, side); }
	// Places a Character randomly on currLand's currMap.
	void placeRandomChar(Character* c){ currLand->placeRandomChar(c); }
	// Places a CraftingStation randomly on currLand's currMap.
	void placeRandomCrafting(CraftingStation* c){ currLand->placeRandomCrafting(c); }
	// Prints currMap
	void printMap(){ currLand->printMap(); }
	// Parses the Player's input
	void movePlayerChar(char c);
	// Updates movements
	void updateMovement(){ return currLand->updateMovement(); }
	// Move Lands if needed
	void moveLands();
	// Getter
	Map* getCurrMap(){ return currLand->currMap; }

private:
	string name;
	Land ***lands;
	int xLandPos, yLandPos;
	Land *currLand;

};