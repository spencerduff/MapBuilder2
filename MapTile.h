#include <iostream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

class MapTile{
public:
	MapTile();
	MapTile(char gTile);
	char getGroundTile(){ return groundTile; }
	char getShowingTile(){ return showingTile; }
	void setGroundTile(char gTile);
	void updateTile(char sTile = NULL);
	void printTile();
	void clearGraves();
	void removeChar(char c);

private:
	char groundTile;
	char showingTile;
	vector<char> underTiles;
	bool isGroundTile();
};