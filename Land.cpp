#include "Land.h"

Land::Land(){
	land = "";
	landSize = 5;
	xMapPos = yMapPos = 2;

	maps = new Map**[landSize];
	for (int i = 0; i < landSize; i++){
		maps[i] = new Map*[landSize];
		for (int j = 0; j < landSize; ++j){
			maps[i][j] = nullptr;
		}
	}
}

Land::~Land(){
	for (int i = 0; i < landSize; ++i){
		for (int j = 0; j < landSize; ++j){
			if (maps[i][j] != NULL){
				delete maps[i][j];
				maps[i][j] = NULL;
			}
		}
		delete[] maps[i];
		maps[i] = NULL;
	}
	delete[] maps;
	maps = NULL;
	currMap = NULL;
}

void Land::createMap(int posX, int posY){
	maps[posX][posY] = new Map();
}

Character* Land::movePlayerCharToNextMap(){
	Character* temp = currMap->getPlayerChar();
	currMap->deleteOldChar();
	currMap = maps[xMapPos][yMapPos];
	temp->setCurrMap(currMap);
	return temp;
}

void OrkLands::createMap(int posX, int posY){
	if (posX == 2 && posY == 2){
		maps[posX][posY] = new OrkMap(true);
	}
	else{
		maps[posX][posY] = new OrkMap();
		maps[posX][posY]->addMobSpawn(new GoblinSpawn(maps[posX][posY]));
	}
}

void HumanLands::createMap(int posX, int posY){
	if (posX == 2 && posY == 2){
		maps[posX][posY] = new HumanMap(true);
	}
	else{
		maps[posX][posY] = new HumanMap();
		maps[xMapPos][yMapPos]->addMobSpawn(new GoblinSpawn(maps[xMapPos][yMapPos]));
	}
}

//If PChar is on an exit, move him to the next map
void Land::moveMaps(){
	std::pair<int, int> prevMapPos(xMapPos, yMapPos);
	if (currMap->getPCharGroundTile()->getSymbol() == '<'){
		xMapPos--;
		createMap(xMapPos, yMapPos);
		placeChar(movePlayerCharToNextMap(), '>');
	}
	else if (currMap->getPCharGroundTile()->getSymbol() == 'v'){
		yMapPos--;
		createMap(xMapPos, yMapPos);
		placeChar(movePlayerCharToNextMap(), '^');
	}
	else if (currMap->getPCharGroundTile()->getSymbol() == '^'){
		yMapPos++;
		createMap(xMapPos, yMapPos);
		placeChar(movePlayerCharToNextMap(), 'v');
	}
	else if (currMap->getPCharGroundTile()->getSymbol() == '>'){
		xMapPos++;
		createMap(xMapPos, yMapPos);
		placeChar(movePlayerCharToNextMap(), '<');
	}
	else{
		return;
	}
	delete maps[prevMapPos.first][prevMapPos.second];
	system("CLS");
	printMap();
}

void Land::movePlayerChar(char c) { 
	currMap->movePlayerChar(c); 
	currMap->moveNPCs();
	currMap->refreshNeeded();
	moveMaps();
}

void Land::movedToNewLand(){
	if (maps[xMapPos][yMapPos] == nullptr){
		delete currMap;
		currMap = nullptr;
		createMap(xMapPos, yMapPos);
		currMap = maps[xMapPos][yMapPos];
	}
}

OrkLands::OrkLands() : Land(){
	land = "Ork Lands.";
	if (xMapPos == 2 && yMapPos == 2){
		maps[xMapPos][yMapPos] = new OrkMap(true);
	}
	else{
		maps[xMapPos][yMapPos] = new OrkMap();
	}
	currMap = maps[xMapPos][yMapPos];
}

HumanLands::HumanLands() : Land(){
	land = "Human Lands.";
	if (xMapPos == 2 && xMapPos == 2){
		maps[xMapPos][yMapPos] = new HumanMap(true);
	}
	else{
		maps[xMapPos][yMapPos] = new HumanMap();
	}
	currMap = maps[xMapPos][yMapPos];
}