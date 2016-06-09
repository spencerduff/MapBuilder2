#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Spell.h"
#include "Velocity.h"

// A flying projectile that will update every Map refresh.
class Projectile{
public:
	Projectile(Velocity iV, Damage d, bool iaoe, int x, int y, Map* iM);
	~Projectile();
	// Overrideable function telling it how to tick.
	virtual bool tick() = 0;

	// Getters
	Symbol* getSymbol(){ return symbol; }
	int getPosX(){ return posX; }
	int getPosY(){ return posY; }
	int getEffectRadius(){ return effectRadius; }

protected:
	Velocity v;
	Damage damage;
	bool AoE;
	int effectRadius;
	int posX, posY;
	float truePosX, truePosY;
	int endX, endY;
	Map* m;
	int range;
	Symbol* symbol;
	bool collidable;
	
	// Returns true if it is activated. Moves the position of the Projectile
	bool iterPos();
	// Returns true if the position the Projectile is on is a collidable groundtile or Character
	bool checkCollision();
	// Overrideable function telling the Projectile how to activate.
	virtual void activate() = 0;
};


class FireballProj : public Projectile{
public:
	FireballProj(Velocity iV, Damage d, int x, int y, Map* iM);
	~FireballProj();
	// Moves the FireballProj then sees if it was activated. Returns false if activated.
	bool tick() override;

private:
	// Explodes the FireballProj in a radius
	void activate() override;
	// Calls the Map explode function to show the explosion on the screen.
	void explode();
};

class StormblastProj : public Projectile{
public:
	StormblastProj(Velocity iV, Damage d, int x, int y, Map* iM);

	bool tick() override;

private:

	void activate() override;

	void explode();

};

#endif