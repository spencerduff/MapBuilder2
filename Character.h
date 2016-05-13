#include <Windows.h>
#include <conio.h>
#include "Weapon.h"
#include "Inventory.h"

class Character{
private:
	int xPos, yPos;
	char movement;
	char character;
	Inventory inv;

	bool isMovement(char m);

public:
	Character();
	Character(int x, int y);
	void setPos(int x, int y);
	char getChar();
	void moveChar(char m = NULL);
	char getMovement();
	int getXpos();
	int getYpos();

};