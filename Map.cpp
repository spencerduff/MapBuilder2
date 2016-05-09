#include "Map.h"

Map::Map(){
	avgSize = rooms[0].getAvgSize();
	//Size of map divided by avg room size plus a constant that makes a good amount of rooms
	numOfRooms = static_cast<int>((xSize*ySize) / ((avgSize*avgSize) + 500));
	numOfTrees = static_cast<int>((xSize*ySize) / ((30) + 500));

	//Initialize map
	map = new MapTile**[ySize];
	for (int i = 0; i < ySize; i++){
		map[i] = new MapTile*[xSize];
		for (int j = 0; j < xSize; j++){
			map[i][j] = new MapTile();
		}
	}
	
	//Set map borders
	for (int i = 0; i < ySize; i++){
		map[i][0]->setGroundTile('|');
		map[i][xSize - 1]->setGroundTile('|');
	}
	for (int i = 0; i < xSize; i++){

		map[0][i]->setGroundTile('_');
		map[ySize - 1][i]->setGroundTile('_');
	}

	//rooms = new Room[numOfRooms];
	////Place Rooms
	//placeRooms(numOfRooms);
	////Place Dirt
	//placeDirt();
	////Make Exits
	//makeExits();

}

void Map::makeExits(){
	int iter = 0, iter2 = 0, iter3 = 0, iter4 = 0;

	//Make iter not in a corner
	iter = (rand() % (ySize - 2)) + 1;
	iter2 = (rand() % (ySize - 2)) + 1;
	iter3 = (rand() % (xSize - 2)) + 1;
	iter4 = (rand() % (xSize - 2)) + 1;
	//While loops make sure exits aren't blocked by rooms
	while (map[iter][1]->getGroundTile() == '#' || map[iter][1]->getGroundTile() == '+'){
		iter = (rand() % (ySize - 2)) + 1;
	}
	map[iter][0]->setGroundTile('<');

	while (map[iter2][xSize - 2]->getGroundTile() == '#' || map[iter2][xSize - 2]->getGroundTile() == '+'){
		iter2 = (rand() % (ySize - 2)) + 1;
	}
	map[iter2][xSize - 1]->setGroundTile('>');

	while (map[1][iter3]->getGroundTile() == '#' || map[1][iter3]->getGroundTile() == '+'){
		iter3 = (rand() % (xSize - 2)) + 1;
	}
	map[0][iter3]->setGroundTile('^');

	while (map[ySize - 2][iter4]->getGroundTile() == '#' || map[ySize - 2][iter4]->getGroundTile() == '+'){
		iter4 = (rand() % (xSize - 2)) + 1;
	}
	map[ySize - 1][iter4]->setGroundTile('v');


}

void Map::placeRooms(int numOfRooms){
	int iter = 0;
	int numOfTries = 0;
	//While there are rooms to go and I haven't tried too much, keep trying to 
	//randomly place rooms, checking to see if they will overlap or be too close,
	//or if they will go off the map.
	while (iter < numOfRooms && numOfTries < 160){
		int roomToPlaceSize = rooms[iter].getRoomSize();
		//Chooses coordinates. Makes sure they're in bounds. If not, subtract the room's
		//size to lower it. Sometimes with big rooms it can cause a negative placement,
		//so account for that and try again.
		int x = rand() % xSize;
		if (x >= xSize - roomToPlaceSize)
			x -= roomToPlaceSize;
		if (x < 0){
			numOfTries++;
			continue;
		}
		int y = rand() % ySize;
		if (y >= ySize - roomToPlaceSize)
			y -= roomToPlaceSize;
		if (y < 0){
			numOfTries++;
			continue;
		}

		//Check if there is something there or close enough, if there is, try again.
		bool shouldPlace = true;
		for (int i = y; i < y + roomToPlaceSize; i++){
			bool breakIter = false;
			for (int j = x; j < x + roomToPlaceSize; j++){
				if (i - 1 > 0){
					if (map[i - 1][j]->getGroundTile() != NULL){
						shouldPlace = false;
						breakIter = true;
						break;
					}
				}
				if (i + 1 < ySize){
					if (map[i + 1][j]->getGroundTile() != NULL){
						shouldPlace = false;
						breakIter = true;
						break;
					}
				}
				if (j - 1 > 0){
					if (map[i][j - 1]->getGroundTile() != NULL){
						shouldPlace = false;
						breakIter = true;
						break;
					}
				}
				if (j + 1 < xSize){
					if (map[i][j + 1]->getGroundTile() != NULL){
						shouldPlace = false;
						breakIter = true;
						break;
					}
				}
				if (map[i][j]->getGroundTile() != NULL){
					shouldPlace = false;
					breakIter = true;
					break;
				}
			}
			if (breakIter)
				break;
		}
		//If there wasn't anything there or too close, place the room on the map and try again.
		if (shouldPlace){
			int k = 0, l = 0;
			for (int i = y; i < y + roomToPlaceSize; i++){
				for (int j = x; j < x + roomToPlaceSize; j++){
					map[i][j]->setGroundTile(rooms[iter].getBoard()[k][l].getGroundTile());
					k++;
				}
				k = 0;
				l++;
			}
			iter++;
		}
		numOfTries++;
	}

}

void Map::placeDirt(){
	//Fill in all NULL spaces with dirt and random plants.
	for (int i = 0; i < ySize; i++){
		for (int j = 0; j < xSize; j++){
			if (map[i][j]->getGroundTile() == NULL){
				if (rand() % 100){
					map[i][j]->setGroundTile('`');
				}
				else{
					map[i][j]->setGroundTile('~');
				}
			}
		}
	}
}

void Map::placeStairs(){
	return;
}

void Map::connectRooms(){
	return;
}

void Map::placeChar(Character* c, char side){
	int iter = 0;

	if (side == '<'){
		while (map[iter++][0]->getGroundTile() != '<');
		c->setPos(1, --iter);
		map[iter][1]->updateTile(c->getChar());
	}else if (side == '>'){
		while (map[iter++][xSize - 1]->getGroundTile() != '>');
		c->setPos(xSize - 2, --iter);
		map[iter][xSize - 2]->updateTile(c->getChar());

	}else if (side == 'v'){
		while (map[ySize - 1][iter++]->getGroundTile() != 'v');
		c->setPos(--iter, ySize - 2);
		map[ySize - 2][iter]->updateTile(c->getChar());

	}else if (side == '^'){
		while (map[0][iter++]->getGroundTile() != '^');
		c->setPos(--iter, 1);
		map[1][iter]->updateTile(c->getChar());

	}
	chars.push_back(c);
}

void Map::movePlayerChar(char c){
	chars[0]->moveChar(c);
	
}

void Map::updateMap(){
	for (int i = 0; i < ySize; i++){
		for (int j = 0; j < xSize; j++){
			return;
		}
	}
}

bool Map::checkNotCollidable(char c){
	if (c == '#' || c == '|' || c == '_')
		return false;
	return true;
}

void Map::moveChar(Character* c, char dir){
	if (dir == 'h'){
		if (c->getXpos() - 1 < 0)
			return;
		if (checkNotCollidable(map[c->getYpos()][c->getXpos() - 1]->getGroundTile())){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos() - 1, c->getYpos());
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	else if (dir == 'j'){
		if (c->getYpos() + 1 >= ySize)
			return;
		if (checkNotCollidable(map[c->getYpos() + 1][c->getXpos()]->getGroundTile())){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos(), c->getYpos() + 1);
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	else if (dir == 'k'){
		if (c->getYpos() - 1 < 0)
			return;
		if (checkNotCollidable(map[c->getYpos() - 1][c->getXpos()]->getGroundTile())){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos(), c->getYpos() - 1);
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	else if (dir == 'l'){
		if (c->getXpos() + 1 >= xSize)
			return;
		if (checkNotCollidable(map[c->getYpos()][c->getXpos() + 1]->getGroundTile())){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos() + 1, c->getYpos());
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	else if (dir == 'y'){
		if (c->getXpos() - 1 < 0 || c->getYpos() - 1 < 0)
			return;
		if (checkNotCollidable(map[c->getYpos() - 1][c->getXpos() - 1]->getGroundTile())){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos() - 1, c->getYpos() - 1);
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	else if (dir == 'u'){
		if (c->getXpos() + 1 >= xSize || c->getYpos() - 1 < 0)
			return;
		if (checkNotCollidable(map[c->getYpos() - 1][c->getXpos() + 1]->getGroundTile())){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos() + 1, c->getYpos() - 1);
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	else if (dir == 'b'){
		if (c->getXpos() - 1 < 0 || c->getYpos() + 1 >= ySize)
			return;
		if (checkNotCollidable(map[c->getYpos() + 1][c->getXpos() - 1]->getGroundTile())){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos() - 1, c->getYpos() + 1);
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	else if (dir == 'n'){
		if (c->getXpos() + 1 >= xSize || c->getYpos() + 1 >= ySize)
			return;
		if (checkNotCollidable(map[c->getYpos() + 1][c->getXpos() + 1]->getGroundTile())){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos() + 1, c->getYpos() + 1);
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	c->moveChar();
}

void Map::updateMovement(){
	for (int i = 0; i < chars.size(); i++){
		if (chars[i]->getMovement() != NULL){
			moveChar(chars[i], chars[i]->getMovement());
		}

	}
}

void Map::printMap(){
	stringstream ss;
	for (int i = 0; i < ySize; i++){
		for (int j = 0; j < xSize; j++){
			ss << map[i][j]->getShowingTile();
		}
		ss << endl;
	}
	ss << endl;
	cout.setf(ios::unitbuf);
	cout << ss.str() << flush;
}

Character* Map::getPlayerChar(){
	return chars[0];
}

char Map::getPCharGroundTile(){
	int x = chars[0]->getXpos();
	int y = chars[0]->getYpos();
	return map[y][x]->getGroundTile();
}

void Map::deleteOldChar(){
	map[chars[0]->getYpos()][chars[0]->getXpos()]->updateTile();
}

void Map::placeTrees(int numOfTrees){

	

	int iter = 0;
	int numOfTries = 0;
	//While there are rooms to go and I haven't tried too much, keep trying to 
	//randomly place rooms, checking to see if they will overlap or be too close,
	//or if they will go off the map.
	while (iter < numOfRooms && numOfTries < 160){
		int treeSizeX = trees[iter]->getTreeSizeX();
		int treeSizeY = trees[iter]->getTreeSizeY();
		
		//Chooses coordinates. Makes sure they're in bounds. If not, subtract the room's
		//size to lower it. Sometimes with big rooms it can cause a negative placement,
		//so account for that and try again.
		int x = rand() % xSize;
		if (x >= xSize - treeSizeX)
			x -= treeSizeX;
		if (x < 0){
			numOfTries++;
			continue;
		}
		int y = rand() % ySize;
		if (y >= ySize - treeSizeY)
			y -= treeSizeY;
		if (y < 0){
			numOfTries++;
			continue;
		}

		//Check if there is something there or close enough, if there is, try again.
		bool shouldPlace = true;
		for (int i = y; i < y + treeSizeY; i++){
			bool breakIter = false;
			for (int j = x; j < x + treeSizeX; j++){
				if (i - 1 > 0){
					if (map[i - 1][j]->getGroundTile() != NULL){
						shouldPlace = false;
						breakIter = true;
						break;
					}
				}
				if (i + 1 < ySize){
					if (map[i + 1][j]->getGroundTile() != NULL){
						shouldPlace = false;
						breakIter = true;
						break;
					}
				}
				if (j - 1 > 0){
					if (map[i][j - 1]->getGroundTile() != NULL){
						shouldPlace = false;
						breakIter = true;
						break;
					}
				}
				if (j + 1 < xSize){
					if (map[i][j + 1]->getGroundTile() != NULL){
						shouldPlace = false;
						breakIter = true;
						break;
					}
				}
				if (map[i][j]->getGroundTile() != NULL){
					shouldPlace = false;
					breakIter = true;
					break;
				}
			}
			if (breakIter)
				break;
		}
		//If there wasn't anything there or too close, place the room on the map and try again.
		if (shouldPlace){
			int k = 0, l = 0;
			for (int i = y; i < y + treeSizeY; i++){
				for (int j = x; j < x + treeSizeX; j++){
					map[i][j]->setGroundTile(trees[iter]->getTree()[k][l]->getGroundTile());
					k++;
				}
				k = 0;
				l++;
			}
			iter++;
		}
		numOfTries++;
	}

}

void Map::placeRocks(){

}

OrkMap::OrkMap() : Map(){
//	rooms = new OrkRoom[numOfRooms];
	//Place Rooms	
//	placeRooms(numOfRooms);
	//Place Trees
	trees = new TreeNode*[numOfTrees];
	for (int i = 0; i < numOfTrees; i++){
		int treeToPlace = rand() % 10;
		if (treeToPlace >= 0 && treeToPlace <= 5){
			trees[i] = new SmallTree();
		}
		else if (treeToPlace >= 6 && treeToPlace <= 8){
			trees[i] = new MedTree();
		}
		else {
			trees[i] = new LargeTree();
		}
	}
	placeTrees(numOfTrees);
	//Place Dirt
	placeDirt();
	//Make Exits
	makeExits();

}

OrkMap::OrkMap(bool starter) : Map(){
	rooms = new OrkRoom[numOfRooms];
	//Place Rooms
	placeRooms(numOfRooms);
	//Place Dirt
	placeDirt();
	//Make Exits
	makeExits();

}

HumanMap::HumanMap() : Map(){
	//Place Trees
	trees = new TreeNode*[numOfTrees];
	for (int i = 0; i < numOfTrees; i++){
		int treeToPlace = rand() % 10;
		if (treeToPlace >= 0 && treeToPlace <= 5){
			trees[i] = new SmallTree();
		}
		else if (treeToPlace >= 6 && treeToPlace <= 8){
			trees[i] = new MedTree();
		}
		else {
			trees[i] = new LargeTree();
		}
	}
	placeTrees(numOfTrees);

	//Place Dirt
	placeDirt();
	//Make Exits
	makeExits();
}

HumanMap::HumanMap(bool starter) : Map(){
	//Place Rooms
	rooms = new HumanRoom[numOfRooms];
	placeRooms(numOfRooms);

	//Place Dirt
	placeDirt();

	//Make Exits
	makeExits();

}