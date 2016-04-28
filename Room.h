#include "MapTile.h"

class Room{
protected:
	static const int maxSize = 15;
	static const int minSize = 5;
	int size;
	int numPorts;
	MapTile** board;
	//Makes 1-4 doors on random sides of a room. 1 door per side.
	void addPorts();
	//Adds walls to borders and floorspace to non-borders
	void makeWalls();

public:
	//Constructs a room, Randomizes size, randomizes number of doors, then adds walls
	//then adds doors.
	Room();
	//Prints the room.
	void printRoom();
	int getRoomSize(){ return size; }
	static double getAvgSize(){ return static_cast<double> (maxSize + minSize) / 2; }
	MapTile** getBoard(){ return board; }
};

class OrkRoom : public Room{
private:
	static const int minSize = 5;
	static const int maxSize = 10;

public:

	OrkRoom();

	void makeWalls(); 

	void addPorts();



};

class HumanRoom : public Room{
private:

public:

	HumanRoom();


};