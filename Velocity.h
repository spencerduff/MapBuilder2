#ifndef VELOCITY_H
#define VELOCITY_H

// Used for Projectiles.
struct Velocity{
	int xDir, yDir;
	int xSpeed, ySpeed;
	int speed;

	void setNULL(){
		xDir = yDir = xSpeed = ySpeed = speed = 0;
	}
};

#endif