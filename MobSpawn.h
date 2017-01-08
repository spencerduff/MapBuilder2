#ifndef MOBSPAWN_H
#define MOBSPAWN_H

#include "Character.h"
#include "Map.h"


class MobSpawn{
public:
	~MobSpawn();
	void removeMe(Character* c);
	virtual void spawnToCapacity() = 0;

protected:
	vector<Character*> spawns;
	int maxNumOfSpawns;
	Map* currMap;
};

class GoblinSpawn : public MobSpawn{
public:
	GoblinSpawn(Map* m);

private:
	void spawnToCapacity() override;
};

#endif