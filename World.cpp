#include "World.h"

World::World(){
	name = "Agon";
	lands = new Land**[3];
	for (int i = 0; i < 3; i++){
		lands[i] = new Land*[5];
	}
	lands[2][3] = new OrkLands();
	lands[2][2] = new HumanLands();
	xLandPos = 2;
	yLandPos = 3;
	currLand = lands[xLandPos][yLandPos];

}

void World::moveLands(){
	if (currLand->currMap->getPCharGroundTile() == '<' && currLand->getXMapPos() == 0){
		int newXMapPos = currLand->getLandSize() - 1;
		Character* temp = currLand->currMap->getPlayerChar();
		currLand->currMap->deleteOldChar();
		int currMapYPos = currLand->getYMapPos();
		currLand = lands[--xLandPos][yLandPos];
		currLand->setXMapPos(newXMapPos);
		currLand->setYMapPos(currMapYPos);
		currLand->currMap = currLand->maps[newXMapPos][currMapYPos];
		placeChar(temp, '>');
	}
	else if (currLand->currMap->getPCharGroundTile() == 'v' && currLand->getYMapPos() == 0){
		int newYMapPos = currLand->getLandSize() - 1;
		Character* temp = currLand->currMap->getPlayerChar();
		currLand->currMap->deleteOldChar();
		int currMapXPos = currLand->getXMapPos();
		currLand = lands[xLandPos][--yLandPos];
		currLand->setXMapPos(currMapXPos);
		currLand->setYMapPos(newYMapPos);
		currLand->currMap = currLand->maps[currMapXPos][newYMapPos];
		placeChar(temp, '^');
	}
	else if (currLand->currMap->getPCharGroundTile() == '^' && currLand->getYMapPos() == currLand->getLandSize() - 1){
		int newYMapPos = 0;
		Character* temp = currLand->currMap->getPlayerChar();
		currLand->currMap->deleteOldChar();
		int currMapXPos = currLand->getXMapPos();
		currLand = lands[xLandPos][++yLandPos];
		currLand->setXMapPos(currMapXPos);
		currLand->setYMapPos(newYMapPos);
		currLand->currMap = currLand->maps[currMapXPos][newYMapPos];
		placeChar(temp, 'v');
	}
	else if (currLand->currMap->getPCharGroundTile() == '>' && currLand->getYMapPos() == currLand->getLandSize() - 1){
		int newXMapPos = 0;
		Character* temp = currLand->currMap->getPlayerChar();
		currLand->currMap->deleteOldChar();
		int currMapYPos = currLand->getYMapPos();
		currLand = lands[++xLandPos][yLandPos];
		currLand->setXMapPos(newXMapPos);
		currLand->setYMapPos(currMapYPos);
		currLand->currMap = currLand->maps[newXMapPos][currMapYPos];
		placeChar(temp, '<');
	}
}

void World::movePlayerChar(char c) { 
	moveLands();
	currLand->movePlayerChar(c); 
}