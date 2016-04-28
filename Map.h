#include "Character.h"
#include <vector>
#include <sstream>
#include "Room.h"



//Each map should have 4 exits to new maps: up, down, left, and right, Unless it is on the
//edge of a Land. Then the exit will not let the player through.
class Map{
protected:
	int numOfRooms;
	Room* rooms;
	static const int ySize = 50;
	static const int xSize = 175;
	double avgSize;
	MapTile** map;

	void updateMap();
	void moveChar(Character* c, char dir);
	void placeStairs();
	void connectRooms();
	//Puts exits on the borders.
	void makeExits();
	//Places how many rooms there need to be placed, but making sure to not try for too
	//long. Randomly places them, but checks to not overlap or go off the map. Doesn't
	//place rooms right next to each other.
	void placeRooms(int numOfRooms);
	//Fills in outside space with dirt and plants.
	void placeDirt();
	//If character is collidable, returns false, else returns true.
	bool checkNotCollidable(char c);

public:

	vector<Character*> chars;
	//Constructs the map. Initializes map and sets the borders.
	//Makes a number of rooms based on the avg room size. Then calls placeRooms and placeDirt.
	Map();

	void placeChar(Character* c, char side = '<');
	void updateMovement();
	void movePlayerChar(char c);
	Character* getPlayerChar();
	char getPCharGroundTile();
	void deleteOldChar();

	//Prints the Map
	void printMap();

};

class OrkMap : public Map{
private:


public:
	OrkMap();


};

class HumanMap : public Map{
private:

public:
	HumanMap();

};