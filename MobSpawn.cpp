#include "MobSpawn.h"

void MobSpawn::removeMe(Character* c){
	for (unsigned int i = 0; i < spawns.size(); i++){
		if (spawns[i] == c){
			swap(spawns[i], spawns.back());
			spawns.pop_back();
		}
	}
	if (spawns.size() == 0)
		spawnToCapacity();
}

GoblinSpawn::GoblinSpawn(Map* m){
	currMap = m;
	maxNumOfSpawns = 5 + (rand()%6);
	spawnToCapacity();
}

void GoblinSpawn::spawnToCapacity(){
	for (int i = spawns.size(); i < maxNumOfSpawns; i++){
		Character* temp = new Goblin(currMap, this);
		spawns.push_back(temp);
		currMap->placeRandomChar(temp);
	}
}