#include "Projectile.h"

Projectile::Projectile(Velocity iV, Damage d, bool iaoe, int x, int y, Map* iM){
	AoE = iaoe;
	v = iV;
	damage = d;
	posX = x;
	posY = y;
	m = iM;
	endX = (iV.xSpeed*iV.xDir + x);
	endY = (iV.ySpeed*iV.yDir + y);
	truePosX = static_cast<float>(x);
	truePosY = static_cast<float>(y);
}

Projectile::~Projectile(){
	delete symbol;
	symbol = nullptr;
}

bool Projectile::iterPos(){
	if (checkCollision())
		return true;

	float avgX = float(v.xSpeed);
	float avgY = float(v.ySpeed);
	int iterSoFarX = -1, iterSoFarY = -1;

	avgX /= v.speed;
	avgY /= v.speed;

	while (iterSoFarX < v.xSpeed / v.speed || iterSoFarY < v.ySpeed / v.speed){
		truePosX += (avgX * v.xDir);
		truePosY += (avgY * v.yDir);

		int addPosX = (int)floor(abs((float)posX - truePosX) + .5);
		int addPosY = (int)floor(abs((float)posY - truePosY) + .5);


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
			range--;
			if (range <= 0){
				activate();
				return true;
			}
		}		
	}
	return false;
}

bool Projectile::checkCollision(){
	if (!m->checkNotCollidable(posX, posY) && collidable){
		activate();
		return true;
	}
	return false;
}

FireballProj::FireballProj(Velocity iV, Damage d, int x, int y, Map* iM) : Projectile(iV, d, true, x, y, iM){
	effectRadius = 2;
	collidable = true;
	range = max(iV.xSpeed, iV.ySpeed);
	if (range > 75)
		range = 75;
	symbol = new Symbol('*', FOREGROUND_RED | FOREGROUND_INTENSITY, BACKGROUND_GREEN | BACKGROUND_RED);
}

bool FireballProj::tick(){
	bool activated = iterPos();
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

StormblastProj::StormblastProj(Velocity iV, Damage d, int x, int y, Map* iM) : Projectile(iV, d, true, x, y, iM){
	effectRadius = 2;
	collidable = false;
	range = 30;
	symbol = new Symbol('*', 15);
}

bool StormblastProj::tick(){
	iterPos();
	if (range > 0)
		activate();
	return false;	
}

void StormblastProj::activate(){
	Character* temp = m->findChar(posX - 1, posY - 1);
	if (temp != NULL){
		// Set velocity away from impact.
		Velocity v;
		v.speed = int(damage.damage);
		v.xDir = -1;
		v.yDir = -1;
		v.xSpeed = int(damage.damage);
		v.ySpeed = int(damage.damage);
		temp->setVelocity(v);
	}
	temp = m->findChar(posX, posY - 1);
	if (temp != NULL){
		// Set velocity away from impact.
		Velocity v;
		v.speed = int(damage.damage);
		v.xDir = 0;
		v.yDir = -1;
		v.xSpeed = int(damage.damage);
		v.ySpeed = int(damage.damage);
		temp->setVelocity(v);
	}
	temp = m->findChar(posX + 1, posY - 1);
	if (temp != NULL){
		// Set velocity away from impact.
		Velocity v;
		v.speed = int(damage.damage);
		v.xDir = 1;
		v.yDir = -1;
		v.xSpeed = int(damage.damage);
		v.ySpeed = int(damage.damage);
		temp->setVelocity(v);
	}
	temp = m->findChar(posX - 1, posY);
	if (temp != NULL){
		// Set velocity away from impact.
		Velocity v;
		v.speed = int(damage.damage);
		v.xDir = -1;
		v.yDir = 0;
		v.xSpeed = int(damage.damage);
		v.ySpeed = int(damage.damage);
		temp->setVelocity(v);
	}
	temp = m->findChar(posX + 1, posY);
	if (temp != NULL){
		// Set velocity away from impact.
		Velocity v;
		v.speed = int(damage.damage);
		v.xDir = 1;
		v.yDir = 0;
		v.xSpeed = int(damage.damage);
		v.ySpeed = int(damage.damage);
		temp->setVelocity(v);
	}
	temp = m->findChar(posX - 1, posY + 1);
	if (temp != NULL){
		// Set velocity away from impact.
		Velocity v;
		v.speed = int(damage.damage);
		v.xDir = -1;
		v.yDir = 1;
		v.xSpeed = int(damage.damage);
		v.ySpeed = int(damage.damage);
		temp->setVelocity(v);
	}
	temp = m->findChar(posX + 1, posY + 1);
	if (temp != NULL){
		// Set velocity away from impact.
		Velocity v;
		v.speed = int(damage.damage);
		v.xDir = 1;
		v.yDir = 1;
		v.xSpeed = int(damage.damage);
		v.ySpeed = int(damage.damage);
		temp->setVelocity(v);
	}
	temp = m->findChar(posX, posY + 1);
	if (temp != NULL){
		// Set velocity away from impact.
		Velocity v;
		v.speed = int(damage.damage);
		v.xDir = 0;
		v.yDir = 1;
		v.xSpeed = int(damage.damage);
		v.ySpeed = int(damage.damage);
		temp->setVelocity(v);
	}
	m->explodeProj(this);
	m->removeProjectile(this);
}