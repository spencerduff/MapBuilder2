#include <iostream>
#include <string>
#include <random>
#include <time.h>

#include "Symbol.h"

using namespace std;

// Tiles on the map. Showing and ground tiles. Also a vector of undertiles to show for things like Characters standing on top of Gravestones.
class MapTile{
public:
	MapTile();
	MapTile(int x, int y);
	MapTile(Symbol* gTile);
	~MapTile();

	// Getters
	Symbol* getGroundTile(){ return groundTile; }
	Symbol* getShowingTile(){ return showingTile; }

	// Setter
	void setGroundTile(Symbol* gTile);
	// Updates the tile to the new symbol and refreshes it.
	void updateTile(Symbol* sTile = NULL);
	// Prints the showing tile.
	void printTile();
	// Clears Gravestone symbols for when they are deleted.
	void clearGraves();
	// Removes a specific Symbol from the undertiles
	void removeChar(Symbol* c);
	// Refreshes the Symbol on the console.
	void refresh();

private:
	int posX, posY;
	Symbol *groundTile;
	Symbol *showingTile;
	vector<Symbol*> underTiles;
	bool isGroundTile();
};