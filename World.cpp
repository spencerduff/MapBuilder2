#include "World.h"

World::World(){
	name = "Agon";
	lands = new Land*[3];
	for (int i = 0; i < 3; i++){
		lands[i] = new Land[5];
	}
	lands[2][3] = OrkLands();
	xLandPos = 2;
	yLandPos = 3;
	currLand = lands[xLandPos][yLandPos];

}