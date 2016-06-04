#ifndef MAP_H
#define MAP_H

#include "Character.h"
#include <vector>
#include <sstream>
#include "Node.h"
#include "Gravestone.h"
#include "Crafting.h"
#include "Projectile.h"

class Gravestone;
class Projectile;

//Each map should have 4 exits to new maps: up, down, left, and right, Unless it is on the
//edge of a Land. Then the exit will not let the player through.
class Map{
public:

	vector<Character*> chars;
	vector<Gravestone*> graves;
	vector<CraftingStation*> crafting;
	//Constructs the map. Initializes map and sets the borders.
	//Makes a number of rooms based on the avg room size. Then calls placeRooms and placeDirt.
	Map();

	void placeChar(Character* c, char side = '<');
	void placeRandomChar(Character *c);
	void placeRandomCrafting(CraftingStation* c);
	void updateMovement();
	void movePlayerChar(char c);
	Character* findChar(int x, int y);

	Character* getPlayerChar();
	Symbol* getPCharGroundTile();

	void deleteOldChar();
	void moveNPCs();

	void kill(Character* c);

	void addProjectile(Projectile* p);
	void removeProjectile(Projectile* p);
	void explodeProj(Projectile* p);

	bool checkNotCollidable(int x, int y);

	void refreshNeeded();

	//Prints the Map
	void printMap();

protected:
	vector<Projectile*> projectiles;
	vector<MapTile*> toRefresh;
	int numOfRooms, numOfTrees, numOfRocks;
	Room* rooms;
	static const int ySize = 50;
	static const int xSize = 175;
	double avgSize;
	MapTile*** map;
	TreeNode** trees;
	RockNode** rocks;

	bool checkCharacter(char c);
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
	//TODO:
	void placeTrees(int numOfTrees);
	//TODO:
	void placeRocks(int numOfRocks);
	bool tryPlaceChar(Character* c, int x, int y);
	bool tryPlaceCrafting(CraftingStation* c, int x, int y);
	void interact(Character* c);
	void lootGrave(Character* c, bool &emptied);
	void craft(Character* c);
	

private:
	void updateProjectiles();
	void tickProjectile();

};

class OrkMap : public Map{
private:


public:
	OrkMap();
	OrkMap(bool starter);

};

class HumanMap : public Map{
private:

public:
	HumanMap();
	HumanMap(bool starter);

};

#endif