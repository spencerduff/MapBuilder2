#include <iostream>
#include <string>
#include <random>
#include <time.h>

#include "Symbol.h"

using namespace std;

class MapTile{
public:
	MapTile();
	MapTile(int x, int y);
	MapTile(Symbol* gTile);
	Symbol* getGroundTile(){ return groundTile; }
	Symbol* getShowingTile(){ return showingTile; }

	void setGroundTile(Symbol* gTile);
	void updateTile(Symbol* sTile = NULL);
	void printTile();
	void clearGraves();
	void removeChar(Symbol* c);
	void refresh();

private:
	int posX, posY;
	Symbol *groundTile;
	Symbol *showingTile;
	vector<Symbol*> underTiles;
	bool isGroundTile();
};