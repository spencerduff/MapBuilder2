#ifndef MOBSPAWN_H
#define MOBSPAWN_H

#include "Character.h"
#include "Map.h"


class MobSpawn{
public:
	void removeMe(Character* c);


protected:
	vector<Character*> spawns;
	int maxNumOfSpawns;
	Map* currMap;
};

class GoblinSpawn : public MobSpawn{
public:
	GoblinSpawn(Map* m);

private:
	void spawnToCapacity();
};

#endif