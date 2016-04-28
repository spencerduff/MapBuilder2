#include "Map.h"


//Should hold a double pointer of Maps
//Maps can be revisited after you move off of them
//Go far enough in any direction to move to a new Land that will be held in a World

class Land{
protected:
	Map** maps;
	int landSize;
	Map currMap;
	int xMapPos, yMapPos;
	string land;

public:

	Land();
	Land(string l);
	void moveMaps();
	void updateMovement(){ currMap.updateMovement(); }
	void movePlayerChar(char c);
	void printMap(){ 
		cout << "You are in " << land << " You are at [" << xMapPos << "] [" << yMapPos << "].";
		if (xMapPos == 2 && yMapPos == 2)
			cout << " This is the starting area for this land.";
		cout << endl;
		currMap.printMap(); 
	}
	void placeChar(Character &c, char side = '<'){ currMap.placeChar(c, side); }

};

class OrkLands : public Land{
private:
	OrkMap** maps;

public:
	OrkLands();

};