#include "Land.h"

Land::Land(){
	land = "";
	landSize = 5;
	xMapPos = yMapPos = 2;
	

}

//If PChar is on an exit, move him to the next map
void Land::moveMaps(){
	if (currMap.getPCharGroundTile() == '<'){
		xMapPos--;
		Character& temp = currMap.getPlayerChar();
		currMap.deleteOldChar();
		currMap = maps[xMapPos][yMapPos];
		placeChar(temp, '>');
	}
	else if (currMap.getPCharGroundTile() == 'v'){
		yMapPos--;
		Character& temp = currMap.getPlayerChar();
		currMap.deleteOldChar();
		currMap = maps[xMapPos][yMapPos];
		placeChar(temp, '^');
	}
	else if (currMap.getPCharGroundTile() == '^'){
		yMapPos++;
		Character& temp = currMap.getPlayerChar();
		currMap.deleteOldChar();
		currMap = maps[xMapPos][yMapPos];
		placeChar(temp, 'v');
	}
	else if (currMap.getPCharGroundTile() == '>'){
		xMapPos++;
		Character& temp = currMap.getPlayerChar();
		currMap.deleteOldChar();
		currMap = maps[xMapPos][yMapPos];
		placeChar(temp, '<');
	}
}

void Land::movePlayerChar(char c) { 
	currMap.movePlayerChar(c); 
	moveMaps();
}

OrkLands::OrkLands() : Land(){
	land = "Ork Lands.";
	maps = new OrkMap*[landSize];
	for (int i = 0; i < landSize; i++){
		maps[i] = new OrkMap[landSize];
	}
	currMap = maps[xMapPos][yMapPos];

}