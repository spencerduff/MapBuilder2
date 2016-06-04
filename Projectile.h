#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Spell.h"
#include "Velocity.h"

class Projectile{
public:
	Projectile(Velocity iV, Damage d, bool iaoe, int x, int y, Map* iM);
	~Projectile();
	virtual bool tick() = 0;

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
	Map* m;
	int range;
	Symbol* symbol;
	
	//Returns true if it is activated
	bool iterPos();
	bool checkCollision();
	virtual void activate() = 0;
};


class FireballProj : public Projectile{
public:
	FireballProj(Velocity iV, Damage d, int x, int y, Map* iM);
	~FireballProj();
	bool tick() override;

private:
	void activate() override;
	void explode();
};

#endif