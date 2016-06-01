#include "Land.h"

Land::Land(){
	land = "";
	landSize = 5;
	xMapPos = yMapPos = 2;
}

//If PChar is on an exit, move him to the next map
void Land::moveMaps(){
	if (currMap->getPCharGroundTile()->getSymbol() == '<'){
		xMapPos--;
		Character* temp = currMap->getPlayerChar();
		currMap->deleteOldChar();
		currMap = maps[xMapPos][yMapPos];
		placeChar(temp, '>');
	}
	else if (currMap->getPCharGroundTile()->getSymbol() == 'v'){
		yMapPos--;
		Character* temp = currMap->getPlayerChar();
		currMap->deleteOldChar();
		currMap = maps[xMapPos][yMapPos];
		placeChar(temp, '^');
	}
	else if (currMap->getPCharGroundTile()->getSymbol() == '^'){
		yMapPos++;
		Character* temp = currMap->getPlayerChar();
		currMap->deleteOldChar();
		currMap = maps[xMapPos][yMapPos];
		placeChar(temp, 'v');
	}
	else if (currMap->getPCharGroundTile()->getSymbol() == '>'){
		xMapPos++;
		Character* temp = currMap->getPlayerChar();
		currMap->deleteOldChar();
		currMap = maps[xMapPos][yMapPos];
		placeChar(temp, '<');
	}
}

void Land::movePlayerChar(char c) { 
	currMap->movePlayerChar(c); 
	currMap->moveNPCs();
	moveMaps();
}

OrkLands::OrkLands() : Land(){
	land = "Ork Lands.";
	maps = new Map**[landSize];
	for (int i = 0; i < landSize; i++){
		maps[i] = new Map*[landSize];
		for (int j = 0; j < landSize; j++)
		{
			if (i == 2 && j == 2){
				maps[i][j] = new OrkMap(true);
				continue;
			}
			maps[i][j] = new OrkMap();
		}
	}
	currMap = maps[xMapPos][yMapPos];

}

HumanLands::HumanLands() : Land(){
	land = "Human Lands.";
	maps = new Map**[landSize];
	for (int i = 0; i < landSize; i++){
		maps[i] = new Map*[landSize];
		for (int j = 0; j < landSize; j++)
		{
			if (i == 2 && j == 2){
				maps[i][j] = new HumanMap(true);
				continue;
			}
			maps[i][j] = new HumanMap();
		}
	}
	currMap = maps[xMapPos][yMapPos];

}