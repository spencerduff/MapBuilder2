#ifndef CHARACTER_H
#define CHARACTER_H


#include <Windows.h>
#include <conio.h>
#include "Inventory.h"
#include "CharacterStats.h"
#include "AI.h"
#include "Resource.h"
#include "Modifiers.h"
#include "Spellbook.h"
#include "Velocity.h"
#include "MobSpawn.h"
#include "Food.h"

class MobSpawn;
class Spellbook;
class Item;
class AI;
class Modifier;
class Food;

// Alignment of a character determines which NPCs will attack
enum RacialAlignment{OrkMahirim, HumanDwarfMirdain, Alfar, evil, monster};

class Character{
public:
	// Character creation that needs to know the map its on for things such as interaction with other Characters on the map and creation of projectiles eminating from the Character
	Character(Map* m);
	virtual ~Character();
	//Character(int x, int y);
	// Used to determine what a Character should do with its input. Actual movement is forced in an update movement function.
	void moveChar(char m = NULL);
	// Used to move the Character and place the Character.
	void setPos(int x, int y);

	// Getters
	Symbol* getChar();
	char getMovement();
	int getXpos();
	int getYpos();
	float getHP();
	string getName();
	AI* getAI();
	Inventory* getBackpack(){ return backpack; }
	Paperdoll* getPaperdoll(){ return paperdoll; }
	CharacterStats* getStats(){ return stats; }
	Velocity getVelocity(){ return v; }

	// Sets the movement of a Character. Used for AI to make sure it is a movement key.
	void setMovement(char m);

	// Equips an item, making sure it's not already equipped. 
	// Calls equip function on an Item which through polymorphism, equips the item to the correct place on the paperdoll.
	void equip(Item *equippable, bool &result);
	// Interacts this character with another. Right now melee attacks, but will eventually do other things like talking or other things.
	void interactCharacter(Character* c);
	// Unequips everything from the paperdoll. Used when a Character dies to clear up Paperdoll pointers.
	void unequipAll();
	// Clears all the UI past the map, and sets the position of the console cursor back to past the map.
	void clearPastMap();
	// Sets the position of the console cursor back to past the map.
	void putCursorPastMap();
	// Puts the cursor on the current Character. Used for aiming projectiles.
	void putCursorOnSelf();
	// Heals a characters stats for the amount.
	void heal(float amount);
	void healStam(float amount);
	void healMana(float amount);
	// Adds a modifier to a Character
	void addMod(Modifier* m);
	// Ticks all of a Character's mods.
	void tickMods();
	// Damages a Character and checks if it needs to kill him.
	void damage(Damage incDamage);
	// Function used for a player to aim a projectile. Returns the velocity of the aimed projectile.
	Velocity aimProjectile();

	void setVelocity(Velocity newVelo){ v = newVelo; }
	void resetVelocity(){ v.setNULL(); }

	bool getFoodSickness(){ return foodSickness; }
	void setFoodSickness(int n){ foodSickness = n; }

protected:
	string name;
	RacialAlignment racialAlignment;
	int xPos, yPos;
	char movement;
	int foodSickness;
	Symbol* character;
	Inventory *backpack;
	Paperdoll *paperdoll;
	CharacterStats *stats;
	AI* ai;
	Spellbook* spellbook;
	vector<Modifier*> modifiers;
	Map* currMap;
	Velocity v;

	Spell* getSpell();

	// Returns if a char is a movement char
	bool isMovement(char m);
	// UI for examining an Item in the backpack
	void examineItem();
	// UI for equipping gear
	void putOnGear();
	// Updates the protections of a Character. Called when something new is equipped.
	void updateProts();
	// Calculates and applies melee damage from this Character to another.
	void calculateMeleeDamage(Character* c);
	// Chooses a random armor to damage. Called when a Character gets hit.
	void damageArmor();
	// Checks if any armor needs to be deleted. Called after Armor is damaged.
	void tryDeleteArmor();

private:
	// Moves the cursor on the console. Used in the AimingProjectile function.
	void moveCursor(char dir);
};

class NPC : public Character{
public:
	NPC(Map* m) : Character(m) {}
	virtual ~NPC() {}
	// Equips all the armor and weapons on an NPC.
	void equipAll();

protected:
	MobSpawn* parentSpawn;

};

class Goblin : public NPC{
public:
	Goblin(Map* m, MobSpawn* ms);
	~Goblin();

private:

};



#endif // !CHARACTER_H