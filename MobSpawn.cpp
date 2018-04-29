#include "MobSpawn.h"

MobSpawn::~MobSpawn(){
	for (auto it = spawns.begin(); it < spawns.end();){
		delete (*it);
		it = spawns.begin();
	}
	spawns.clear();
}

void MobSpawn::removeMe(Character* c){
	for (unsigned int i = 0; i < spawns.size(); i++){
		if (spawns[i] == c){
			swap(spawns[i], spawns.back());
			spawns.pop_back();
		}
	}
}

int MobSpawn::getAgentNum(){
	return NUM_OF_AGENTS;
}

GoblinSpawn::GoblinSpawn(Map* m){
	currMap = m;
	maxNumOfSpawns = NUM_OF_AGENTS;
	spawnToCapacity();
}

void GoblinSpawn::spawnToCapacity(){
	for (int i = spawns.size(); i < maxNumOfSpawns; i++){
		Character* temp = new Goblin(currMap, this);
		spawns.push_back(temp);
		currMap->placeRandomChar(temp);
	}
}