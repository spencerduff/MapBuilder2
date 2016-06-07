#ifndef ROOM_H
#define ROOM_H

#include "MapTile.h"

// Rooms are collidable buildings that can be added to a Map.
class Room{
public:
	//Constructs a room, Randomizes size, randomizes number of doors, then adds walls
	//then adds doors.
	Room();
	//Prints the room.
	void printRoom();
	// Getters
	int getRoomSize(){ return size; }
	static double getAvgSize(){ return static_cast<double> (maxSize + minSize) / 2; }
	MapTile** getBoard(){ return board; }

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
};

class OrkRoom : public Room{
public:
	OrkRoom();
	// Makes a tent shaped room
	void makeWalls(); 
	// Adds a door to the bottom
	void addPorts();

private:
	static const int minSize = 5;
	static const int maxSize = 10;
};

class HumanRoom : public Room{
public:
	HumanRoom();

private:

};


#endif