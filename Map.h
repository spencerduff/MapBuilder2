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

// Each map should have 4 exits to new maps: up, down, left, and right,
// TODO:
// Unless it is on the edge of the World. Then the exit will not let the player through.
class Map{
public:
	// The map knows about all its Characters, Gravestones, and CraftingStations.
	vector<Character*> chars;
	vector<Gravestone*> graves;
	vector<CraftingStation*> crafting;
	// Constructs the map. Initializes map and sets the borders.
	// Makes a number of rooms based on the avg room size. Then calls placeRooms and placeDirt.
	Map();

	// Finds the side of the Map and places the Character there. Used for movement through Maps.
	void placeChar(Character* c, char side = '<');
	// Randomly places the Character in an allowable MapTile.
	void placeRandomChar(Character *c);
	// Randomly places the CraftingStation in an allowable MapTile.
	void placeRandomCrafting(CraftingStation* c);
	// Updates the game. Movement of everything is applied. Everything time based is ticked.
	void updateMovement();
	// Determines what the Player's input should do to the Player Character
	void movePlayerChar(char c);
	// Finds a Character in the given coordinates. Used for interacting Characters and Projectile interaction.
	Character* findChar(int x, int y);

	// Getters
	Character* getPlayerChar();
	Symbol* getPCharGroundTile();

	// When moving off maps, updates the old tile the Character used to be on.
	void deleteOldChar();
	// Moves NPCs according to their AI
	void moveNPCs();

	// Kills a Character and deletes it, leaving a Gravestone of his backpack.
	void kill(Character* c);

	// Adding a removing projectiles to and from the Map.
	void addProjectile(Projectile* p);
	void removeProjectile(Projectile* p);
	// For AoE Projectiles, shows a graphic for their explosion.
	void explodeProj(Projectile* p);

	// Checks if a position is a collidable groundTile or Character
	bool checkNotCollidable(int x, int y);
	bool checkNotCollidableMapTile(int x, int y);

	// Refreshes the refresh list, then empties it.
	void refreshNeeded();

	// Prints the Map
	void printMap();

protected:
	// The projectiles held by the Map
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

	// Checks if a char represents a Character
	bool checkCharacter(char c);
	// Interacts or moves the Character to the given direction.
	void moveChar(Character* c, char dir);
	// TODO:
	void placeStairs();
	// TODO:
	void connectRooms();
	// Puts exits on the borders.
	void makeExits();
	// Places how many rooms there need to be placed, but making sure to not try for too
	// long. Randomly places them, but checks to not overlap or go off the map. Doesn't
	// place rooms right next to each other.
	void placeRooms(int numOfRooms);
	// Fills in outside space with dirt and plants.
	void placeDirt();
	// If character is collidable, returns false, else returns true.
	bool checkNotCollidable(char c);
	// Places Trees from the Map's array of Trees
	void placeTrees(int numOfTrees);
	// Places Rocks from the Map's array of Rocks
	void placeRocks(int numOfRocks);
	// Tries to place a Character at a location. Used when randomly placing a Character
	bool tryPlaceChar(Character* c, int x, int y);
	// Same as above but with a CraftingStation
	bool tryPlaceCrafting(CraftingStation* c, int x, int y);
	// The 'use key' for a Character. Causes the Character to interact with the tile below him.
	void interact(Character* c);
	// Loots the grave and passes back if it's empty by reference
	void lootGrave(Character* c, bool &emptied);
	// Through polymorphism calls the correct crafting based on what station the Character is standing on.
	void craft(Character* c);
	

private:
	// Draws the projectiles to their new location.
	void updateProjectiles();
	// Ticks the projectiles, making them update their movement.
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