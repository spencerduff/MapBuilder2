#include "World.h"

World::World(){
	name = "Agon";
	lands = new Land**[3];
	for (int i = 0; i < 3; i++){
		lands[i] = new Land*[5];
	}
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 5; ++j){
			lands[i][j] = NULL;
		}
	}
	lands[2][3] = new OrkLands();
	lands[2][2] = new HumanLands();
	xLandPos = 2;
	yLandPos = 3;
	currLand = lands[xLandPos][yLandPos];

}

World::~World(){
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 5; ++j){
			if (lands[i][j] != NULL){
				delete lands[i][j];
				lands[i][j] = NULL;
			}
		}
		delete[] lands[i];
		lands[i] = NULL;
	}
	delete[] lands;
	lands = NULL;
	currLand = NULL;
}

void World::placeChar(Character* c, char side){
	currLand->placeChar(c, side);
}

void World::moveLands(){
	if (currLand->currMap->getPCharGroundTile()->getSymbol() == '<' && currLand->getXMapPos() == 0){
		cout << "You have moved to ";
		int newXMapPos = currLand->getLandSize() - 1;
		Character* temp = currLand->currMap->getPlayerChar();
		currLand->currMap->deleteOldChar();
		int currMapYPos = currLand->getYMapPos();
		currLand = lands[--xLandPos][yLandPos];
		currLand->setXMapPos(newXMapPos);
		currLand->setYMapPos(currMapYPos);
		currLand->movedToNewLand();
		currLand->currMap = currLand->maps[newXMapPos][currMapYPos];
		placeChar(temp, '>');
	}
	else if (currLand->currMap->getPCharGroundTile()->getSymbol() == 'v' && currLand->getYMapPos() == 0){
		cout << "You have moved to ";
		int newYMapPos = currLand->getLandSize() - 1;
		Character* temp = currLand->currMap->getPlayerChar();
		currLand->currMap->deleteOldChar();
		int currMapXPos = currLand->getXMapPos();
		currLand = lands[xLandPos][--yLandPos];
		currLand->setXMapPos(currMapXPos);
		currLand->setYMapPos(newYMapPos);
		currLand->movedToNewLand();
		currLand->currMap = currLand->maps[currMapXPos][newYMapPos];
		placeChar(temp, '^');
	}
	else if (currLand->currMap->getPCharGroundTile()->getSymbol() == '^' && currLand->getYMapPos() == currLand->getLandSize() - 1){
		cout << "You have moved to ";
		int newYMapPos = 0;
		Character* temp = currLand->currMap->getPlayerChar();
		currLand->currMap->deleteOldChar();
		int currMapXPos = currLand->getXMapPos();
		currLand = lands[xLandPos][++yLandPos];
		currLand->setXMapPos(currMapXPos);
		currLand->setYMapPos(newYMapPos);
		currLand->movedToNewLand();
		currLand->currMap = currLand->maps[currMapXPos][newYMapPos];
		placeChar(temp, 'v');
	}
	else if (currLand->currMap->getPCharGroundTile()->getSymbol() == '>' && currLand->getYMapPos() == currLand->getLandSize() - 1){
		cout << "You have moved to ";
		int newXMapPos = 0;
		Character* temp = currLand->currMap->getPlayerChar();
		currLand->currMap->deleteOldChar();
		int currMapYPos = currLand->getYMapPos();
		currLand = lands[++xLandPos][yLandPos];
		currLand->setXMapPos(newXMapPos);
		currLand->setYMapPos(currMapYPos);
		currLand->movedToNewLand();
		currLand->currMap = currLand->maps[newXMapPos][currMapYPos];
		placeChar(temp, '<');
	}
	else {
		return;
	}
	cout << currLand->getLand() << "." << endl;
	system("CLS");
	printMap();
}

void World::movePlayerChar(char c) { 
	moveLands();
	currLand->movePlayerChar(c);
}