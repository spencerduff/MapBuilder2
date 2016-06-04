#include "Projectile.h"

Projectile::Projectile(Velocity iV, Damage d, bool iaoe, int x, int y, Map* iM){
	AoE = iaoe;
	v = iV;
	damage = d;
	posX = x;
	posY = y;
	m = iM;
}

Projectile::~Projectile(){
	delete symbol;
	symbol = NULL;
}

bool Projectile::iterPos(){
	if (checkCollision())
		return true;

	int toDivX = v.xSpeed;
	int toDivY = v.ySpeed;

	if (v.ySpeed == 0)
		toDivY = 1;
	if (v.xSpeed == 0)
		toDivX = 1;
	float avgX = float(v.xSpeed) / float(toDivY);
	float avgY = float(v.ySpeed) / float(toDivX);
	float toIterX = 0, toIterY = 0;
	int iterSoFarX = -1, iterSoFarY = -1;

	avgX /= v.speed;
	avgY /= v.speed;

	while (iterSoFarX < v.xSpeed / v.speed || iterSoFarY < v.ySpeed / v.speed){
		toIterX += avgX;
		toIterY += avgY;

		int addPosX = floor(toIterX + .5);
		int addPosY = floor(toIterY + .5);

		if (addPosX >= 1)
			toIterX = 0;
		if (addPosY >= 1)
			toIterY = 0;

		if (iterSoFarX == -1)
			iterSoFarX = 0;
		if (iterSoFarY == -1)
			iterSoFarY = 0;

		iterSoFarX += addPosX;
		iterSoFarY += addPosY;

		while (addPosX > 0 || addPosY > 0){
			if (addPosX > 0){
				posX += v.xDir;
				addPosX--;
			}
			if (addPosY > 0){
				posY += v.yDir;
				addPosY--;
			}
			if (checkCollision())
				return true;
		}		
	}
	return false;
}

bool Projectile::checkCollision(){
	if (!m->checkNotCollidable(posX, posY)){
		activate();
		return true;
	}
	return false;
}

FireballProj::FireballProj(Velocity iV, Damage d, int x, int y, Map* iM) : Projectile(iV, d, true, x, y, iM){
	effectRadius = 2;
	range = 75;
	symbol = new Symbol('*', FOREGROUND_RED | FOREGROUND_INTENSITY, BACKGROUND_GREEN | BACKGROUND_RED);
}

FireballProj::~FireballProj(){
}

bool FireballProj::tick(){
	float a, b, c;
	a = v.xSpeed;
	b = v.ySpeed;
	c = a*a + b*b;
	c = sqrt(c);
	bool activated = iterPos();
	range -= c / v.speed;
	if (activated == false){
		if (range <= 0){
			activate();
			return false;
		}
	}
	else return false;
	return true;
}

void FireballProj::activate(){
	Character* temp = m->findChar(posX, posY);
	if (temp != NULL){
		temp->damage(damage);
	}
	temp = m->findChar(posX - 1, posY - 1);
	if (temp != NULL){
		damage.damage /= 3;
		temp->damage(damage);
	}
	temp = m->findChar(posX, posY - 1);
	if (temp != NULL){
		damage.damage /= 3;
		temp->damage(damage);
	}
	temp = m->findChar(posX + 1, posY - 1);
	if (temp != NULL){
		damage.damage /= 3;
		temp->damage(damage);
	}
	temp = m->findChar(posX - 1, posY);
	if (temp != NULL){
		damage.damage /= 3;
		temp->damage(damage);
	}
	temp = m->findChar(posX + 1, posY);
	if (temp != NULL){
		damage.damage /= 3;
		temp->damage(damage);
	}
	temp = m->findChar(posX - 1, posY + 1);
	if (temp != NULL){
		damage.damage /= 3;
		temp->damage(damage);
	}
	temp = m->findChar(posX + 1, posY + 1);
	if (temp != NULL){
		damage.damage /= 3;
		temp->damage(damage);
	}
	temp = m->findChar(posX, posY + 1);
	if (temp != NULL){
		damage.damage /= 3;
		temp->damage(damage);
	}
	explode();
	m->removeProjectile(this);
}

void FireballProj::explode(){

	m->explodeProj(this);
}