#include "Map.h"
#include "TimeF.h"
#include "fstream"
#include <stdlib.h> 
#include <windows.h>

Map::Map(){
	avgSize = rooms[0].getAvgSize();
	//Size of map divided by avg room size plus a constant that makes a good amount of rooms
	numOfRooms = static_cast<int>((xSize*ySize) / ((avgSize*avgSize) + 500));

	//Initialize map
	map = new MapTile**[ySize];
	for (int i = 0; i < ySize; i++){
		map[i] = new MapTile*[xSize];
		for (int j = 0; j < xSize; j++){
			map[i][j] = new MapTile(j, i);
		}
	}
	
	//Set map borders
	for (int i = 0; i < ySize; i++){
		map[i][0]->setGroundTile(new Symbol('|', 8));
		map[i][xSize - 1]->setGroundTile(new Symbol('|', 8));
	}
	for (int i = 0; i < xSize; i++){

		map[0][i]->setGroundTile(new Symbol('_', 8));
		map[ySize - 1][i]->setGroundTile(new Symbol('_', 8));
	}

}

Map::~Map(){
	for (auto it = graves.begin(); it < graves.end(); ++it){
		delete (*it);
	}
	for (auto it = crafting.begin(); it < crafting.end(); ++it){
		delete (*it);
	}
	for (auto it = projectiles.begin(); it < projectiles.end(); ++it){
		delete (*it);
	}
	for (auto it = spawns.begin(); it < spawns.end(); ++it){
		delete (*it);
	}

	chars.clear();
	graves.clear();
	crafting.clear();
	projectiles.clear();
	spawns.clear();
	
	delete[] rooms;
	rooms = nullptr;

	for (int i = 0; i < ySize; ++i){
		for (int j = 0; j < xSize; ++j){
			if (map[i][j] != nullptr){
				delete map[i][j];
				map[i][j] = nullptr;
			}
		}
		delete[] map[i];
		map[i] = nullptr;
	}
	delete[] map;
	map = nullptr;

	for (int i = 0; i < numOfTrees; ++i){
		if (trees[i] != nullptr){
			delete[] trees[i];
			trees[i] = nullptr;
		}
	}
	delete[] trees;
	trees = nullptr;


	for (int i = 0; i < numOfRocks; ++i){
		if (rocks[i] != nullptr){
			delete[] rocks[i];
			rocks[i] = nullptr;
		}
	}
	delete[] rocks;
	rocks = nullptr;
}

void Map::makeExits(){
	int iter = 0, iter2 = 0, iter3 = 0, iter4 = 0;

	//Make iter not in a corner
	iter = (rand() % (ySize - 2)) + 1;
	iter2 = (rand() % (ySize - 2)) + 1;
	iter3 = (rand() % (xSize - 2)) + 1;
	iter4 = (rand() % (xSize - 2)) + 1;
	//While loops make sure exits aren't blocked by rooms
	while (map[iter][1]->getGroundTile()->getSymbol() == '#' || map[iter][1]->getGroundTile()->getSymbol() == '+'){
		iter = (rand() % (ySize - 2)) + 1;
	}
	map[iter][0]->setGroundTile(new Symbol('<', 15));

	while (map[iter2][xSize - 2]->getGroundTile()->getSymbol() == '#' || map[iter2][xSize - 2]->getGroundTile()->getSymbol() == '+'){
		iter2 = (rand() % (ySize - 2)) + 1;
	}
	map[iter2][xSize - 1]->setGroundTile(new Symbol('>', 15));

	while (map[1][iter3]->getGroundTile()->getSymbol() == '#' || map[1][iter3]->getGroundTile()->getSymbol() == '+'){
		iter3 = (rand() % (xSize - 2)) + 1;
	}
	map[0][iter3]->setGroundTile(new Symbol('^', 15));

	while (map[ySize - 2][iter4]->getGroundTile()->getSymbol() == '#' || map[ySize - 2][iter4]->getGroundTile()->getSymbol() == '+'){
		iter4 = (rand() % (xSize - 2)) + 1;
	}
	map[ySize - 1][iter4]->setGroundTile(new Symbol('v', 15));


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
					map[i][j]->setGroundTile(rooms[iter].getBoard()[k][l]->getGroundTile());
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
					if (rand() % 4)
						map[i][j]->setGroundTile(new Symbol('`', 2));
					else 
						map[i][j]->setGroundTile(new Symbol('`', 6));
				}
				else{
					map[i][j]->setGroundTile(new Symbol('~', 10));
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
		while (map[iter++][0]->getGroundTile()->getSymbol() != '<');
		c->setPos(1, --iter);
		map[iter][1]->updateTile(c->getChar());
	}else if (side == '>'){
		while (map[iter++][xSize - 1]->getGroundTile()->getSymbol() != '>');
		c->setPos(xSize - 2, --iter);
		map[iter][xSize - 2]->updateTile(c->getChar());

	}else if (side == 'v'){
		while (map[ySize - 1][iter++]->getGroundTile()->getSymbol() != 'v');
		c->setPos(--iter, ySize - 2);
		map[ySize - 2][iter]->updateTile(c->getChar());

	}else if (side == '^'){
		while (map[0][iter++]->getGroundTile()->getSymbol() != '^');
		c->setPos(--iter, 1);
		map[1][iter]->updateTile(c->getChar());

	}
	if (!chars.empty()){
		if (chars[0] == c)
			return;
		else{
			chars.push_back(c);
			swap(chars.back(), chars[0]);
		}
	}
	else {
		chars.push_back(c);
	}
}

void Map::placeRandomChar(Character* c){
	bool notPlaced = true;
	int triesToGo = 200;

	while (notPlaced && triesToGo){
		int x = rand() % (xSize - 1);
		if (x == 0)
			x++;
		int y = rand() % (ySize - 1);
		if (y == 0)
			y++;

		if (tryPlaceChar(c, x, y))
			notPlaced = false;
		triesToGo--;
	}
	if (notPlaced == false)
		chars.push_back(c);
}

void Map::placeRandomCrafting(CraftingStation* c){
	bool notPlaced = true;
	int triesToGo = 200;

	while (notPlaced && triesToGo){
		int x = rand() % (xSize - 1);
		if (x == 0)
			x++;
		int y = rand() % (ySize - 1);
		if (y == 0)
			y++;
		if (tryPlaceCrafting(c, x, y))
			notPlaced = false;
		triesToGo--;
	}
	if (notPlaced == false)
		crafting.push_back(c);
}

bool Map::tryPlaceChar(Character* c, int x, int y){
	if (checkNotCollidable(map[y][x]->getShowingTile()->getSymbol())){
		c->setPos(x, y);
		map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		return true;
	}
	else return false;
}

bool Map::tryPlaceCrafting(CraftingStation* c, int x, int y){
	if (checkNotCollidable(map[y][x]->getShowingTile()->getSymbol())){
		c->setPos(x, y);
		map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		return true;
	}
	else return false;
}

void Map::movePlayerChar(char c){
	chars[0]->moveChar(c);
}

bool Map::checkNotCollidable(int x, int y){
	return checkNotCollidable(map[y][x]->getGroundTile()->getSymbol()) && !checkCharacter(map[y][x]->getShowingTile()->getSymbol());
}

bool Map::checkNotCollidableMapTile(int x, int y){
	return checkNotCollidable(map[y][x]->getGroundTile()->getSymbol());
}

bool Map::checkNotCollidable(char c){
	if (c == '#' || c == '|' || c == '_' || c == 'x')
		return false;
	return true;
}

bool Map::checkCharacter(char c){
	if (c == '@' || c == 'g' || c == 'O')
		return true;
	else return false;
}

Character* Map::findChar(int x, int y){
	for (unsigned int i = 0; i < chars.size(); i++){
		if (chars[i]->getXpos() == x && chars[i]->getYpos() == y)
			return chars[i];
	}
	return NULL;
}

void Map::moveChar(Character* c, char dir){
	MoveDir moveDir = getMoveDir(dir);

	// Don't move to the space you're already on
	if (moveDir.x == 0 && moveDir.y == 0)
		return;

	if (!isInsideBoard(c->getXpos() + moveDir.x, c->getYpos() + moveDir.y))
		return;
	
	if (checkCharacter(map[c->getYpos() + moveDir.y][c->getXpos() + moveDir.x]->getShowingTile()->getSymbol())){
		Character* toInteract = findChar(c->getXpos() + moveDir.x, c->getYpos() + moveDir.y);
		c->interactCharacter(toInteract);
	}
	else if (checkNotCollidable(map[c->getYpos() + moveDir.y][c->getXpos() + moveDir.x]->getGroundTile()->getSymbol())){
		map[c->getYpos()][c->getXpos()]->updateTile();
		c->setPos(c->getXpos() + moveDir.x, c->getYpos() + moveDir.y);
		map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
	}
	
	c->moveChar();
}

bool Map::isInsideBoard(int x, int y){
	if (x < 0 || x >= xSize)
		return false;
	if (y < 0 || y >= ySize)
		return false;
	return true;
}

MoveDir Map::getMoveDir(char dir){
	MoveDir moveDir;

	switch (dir){
	case 'h':
	case 'y':
	case 'b':
		moveDir.x = -1;
		break;
	case 'j':
	case 'k':
	default:
		moveDir.x = 0;
		break;
	case 'l':
	case 'u':
	case 'n':
		moveDir.x = 1;
	}

	switch (dir){
	case 'y':
	case 'u':
	case 'k':
		moveDir.y = -1;
		break;
	case 'h':
	case 'l':
	default:
		moveDir.y = 0;
		break;
	case 'b':
	case 'n':
	case 'j':
		moveDir.y = 1;
	}
	return moveDir;
}

void Map::kill(Character* c){
	cout << c->getName() << " has been slain." << endl;
	map[c->getYpos()][c->getXpos()]->removeChar(c->getChar());
	c->unequipAll();
	Gravestone* g = new Gravestone(c);
	if (g->getGrave()->inventory.empty()){
		delete g;
		g = NULL;
	}
	if (g != NULL){
		graves.push_back(g);
		map[c->getYpos()][c->getXpos()]->updateTile(g->getMarker());
	}
	else map[c->getYpos()][c->getXpos()]->updateTile();
	for (unsigned int i = 1; i < chars.size(); i++)
		if (chars[i] == c){
			swap(chars[i], chars.back());
			chars.pop_back();
		}
	delete c;
	c = NULL;
}

void Map::updateProjectiles(){
	for (unsigned int i = 0; i < projectiles.size(); i++){
		map[projectiles[i]->getPosY()][projectiles[i]->getPosX()]->updateTile();
		if (projectiles[i]->tick()){
			map[projectiles[i]->getPosY()][projectiles[i]->getPosX()]->updateTile(projectiles[i]->getSymbol());
		}
		else i--;
	}
}

void Map::explodeProj(Projectile* p){
	int startX = p->getPosX() - (p->getEffectRadius() - 1);
	int endX = p->getPosX() + (p->getEffectRadius() - 1);
	int startY = p->getPosY() - (p->getEffectRadius() - 1);
	int endY = p->getPosY() + (p->getEffectRadius() - 1);

	if (startX < 1)
		startX = 1;
	if (startY < 1)
		startY = 1;
	if (endX > xSize - 1)
		endX = xSize - 1;
	if (endY > ySize - 1)
		endY = ySize - 1;

	for (int i = startX; i <= endX; i++){
		for (int j = startY; j <= endY; j++){
			map[j][i]->updateTile(p->getSymbol());
			if (j == p->getPosY() && i == p->getPosX())
				continue;
			toRefresh.push_back(map[j][i]);
		}
	}

}

void Map::refreshNeeded(){
	for (unsigned int i = 0; i < toRefresh.size(); i++){
		toRefresh[i]->updateTile();
	}
	toRefresh.clear();
}

void Map::addProjectile(Projectile* p){
	projectiles.push_back(p);
	map[p->getPosY()][p->getPosX()]->updateTile(p->getSymbol());
}

void Map::removeProjectile(Projectile* p){
	for (unsigned int i = 0; i < projectiles.size(); i++){
		if (projectiles[i] == p){
			map[p->getPosY()][p->getPosX()]->updateTile();
			swap(projectiles[i], projectiles.back());
			projectiles.pop_back();
			delete p;
			p = nullptr;
		}
	}
}

void Map::updateMovement(){
	for (unsigned int i = 0; i < chars.size(); i++){
		chars[i]->tickMods();	
		if (chars[i]->getMovement() == 'f'){
			interact(chars[i]);
			chars[0]->clearPastMap();
		}
		if (knockback(chars[i])){
			if (chars[i]->getMovement() != ' '){
				chars[i]->resetVelocity();
			}
		}
		else
			moveChar(chars[i], chars[i]->getMovement());
	}
	updateProjectiles();
	chars[0]->putCursorPastMap();
}

void Map::interact(Character* c){
	bool clearGrave = false;
	lootGrave(c, clearGrave);
	if (clearGrave)
		map[c->getYpos()][c->getXpos()]->clearGraves();
	craft(c);

	return;
}

void Map::lootGrave(Character* c, bool &emptied){
	for (unsigned int i = 0; i < graves.size(); i++){
		if (c->getXpos() == graves[i]->getXpos() && c->getYpos() == graves[i]->getYpos())
			if (graves[i]->lootGrave(c))
				emptied = true;
	}
	return;
}

void Map::craft(Character* c){
	for (unsigned int i = 0; i < crafting.size(); i++){
		if (c->getXpos() == crafting[i]->getXpos() && c->getYpos() == crafting[i]->getYpos())
			(crafting[i]->craft(c));
	}
}

void Map::printMap(){
	for (int i = 0; i < ySize; i++){
		for (int j = 0; j < xSize; j++){
			cout << *(map[i][j]->getShowingTile());
		}
		cout << endl;
	}
	cout << endl;
	cout << flush;
}

Character* Map::getPlayerChar(){
	return chars[0];
}

Symbol* Map::getPCharGroundTile(){
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
	while (iter < numOfTrees && numOfTries < 250){
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

void Map::placeRocks(int numOfRocks){
	int iter = 0;
	int numOfTries = 0;
	//While there are rooms to go and I haven't tried too much, keep trying to 
	//randomly place rooms, checking to see if they will overlap or be too close,
	//or if they will go off the map.
	while (iter < numOfRocks && numOfTries < 300){
		int rockToPlaceSize = rocks[iter]->getRockSize();
		//Chooses coordinates. Makes sure they're in bounds. If not, subtract the room's
		//size to lower it. Sometimes with big rooms it can cause a negative placement,
		//so account for that and try again.
		int x = rand() % xSize;
		if (x >= xSize - rockToPlaceSize)
			x -= rockToPlaceSize;
		if (x < 0){
			numOfTries++;
			continue;
		}
		int y = rand() % ySize;
		if (y >= ySize - rockToPlaceSize)
			y -= rockToPlaceSize;
		if (y < 0){
			numOfTries++;
			continue;
		}

		//Check if there is something there or close enough, if there is, try again.
		bool shouldPlace = true;
		for (int i = y; i < y + rockToPlaceSize; i++){
			bool breakIter = false;
			for (int j = x; j < x + rockToPlaceSize; j++){
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
			for (int i = y; i < y + rockToPlaceSize; i++){
				for (int j = x; j < x + rockToPlaceSize; j++){
					map[i][j]->setGroundTile(rocks[iter]->getRock()[k][l]->getGroundTile());
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

void Map::moveNPCs(){
	double total = 0;
	for (unsigned int i = 1; i < chars.size(); i++){
		auto start = std::chrono::steady_clock::now();
		chars[i]->getAI()->move();
		Sleep(10);
		auto end = std::chrono::steady_clock::now();
		total += std::chrono::duration<double, std::nano>(end - start).count();
	}
	std::ofstream thinkTimes("think_time.txt", ofstream::app);
	if (thinkTimes.is_open()){
		thinkTimes << total - ((chars.size() - 1) * std::chrono::duration<double, std::nano>(10000000).count()) << " " << total / (chars.size() - 1) - std::chrono::duration<double, std::nano>(10000000).count() << "\n";
	}
}

bool Map::knockback(Character* c){
	if (c->getVelocity().speed == 0) return false;
	int hopsToGo = c->getVelocity().speed;
	while (hopsToGo-- > 0){
		if (checkExit(map[c->getYpos() + c->getVelocity().yDir][c->getXpos() + c->getVelocity().xDir]->getGroundTile()->getSymbol()))
			return true;
		if (checkNotCollidable(c->getXpos() + c->getVelocity().xDir, c->getYpos() + c->getVelocity().yDir)){
			map[c->getYpos()][c->getXpos()]->updateTile();
			c->setPos(c->getXpos() + c->getVelocity().xDir, c->getYpos() + c->getVelocity().yDir);
			map[c->getYpos()][c->getXpos()]->updateTile(c->getChar());
		}
	}
	return true;
}

bool Map::checkExit(char tile){
	if (tile == 'v' || tile == '^' || tile == '<' || tile == '>')
		return true;
	return false;
}

void Map::addMobSpawn(MobSpawn* m){
	spawns.push_back(m);
}

OrkMap::OrkMap() : Map(){
//	rooms = new OrkRoom[numOfRooms];
	//Place Rooms	
//	placeRooms(numOfRooms);
	//Place Trees
	numOfTrees = static_cast<int>((xSize*ySize) / ((30) + 500));
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

	//Place Rocks
	numOfRocks = static_cast<int>((xSize*ySize) / ((30) + 225));
	rocks = new RockNode*[numOfRocks];
	for (int i = 0; i < numOfRocks; i++){
		int rockToPlace = rand() % 10;
		if (rockToPlace >= 0 && rockToPlace <= 5){
			rocks[i] = new SmallRock();
		}
		else if (rockToPlace >= 6 && rockToPlace <= 8){
			rocks[i] = new MedRock();
		}
		else {
			rocks[i] = new LargeRock();
		}
	}
	placeRocks(numOfRocks);

	placeDirt();

	makeExits();

}

OrkMap::OrkMap(bool starter) : Map(){
	rooms = new OrkRoom[numOfRooms];
	placeRooms(numOfRooms);

	placeDirt();

	makeExits();

	this->placeRandomChar(new OrkGuide(this));

	this->placeRandomCrafting(new Thaumaturgy());

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

	placeDirt();

	makeExits();
}

HumanMap::HumanMap(bool starter) : Map(){
	rooms = new HumanRoom[numOfRooms];
	placeRooms(numOfRooms);
	
	placeDirt();

	makeExits();

	this->placeRandomCrafting(new Thaumaturgy());

}