#include "Room.h"


class TreeNode{
protected:
	MapTile*** tree;
	int treeSizeX, treeSizeY;

public:

	MapTile*** getTree(){ return tree; }
	int getTreeSizeX(){ return treeSizeX; }
	int getTreeSizeY(){ return treeSizeY; }

};

class SmallTree : public TreeNode{

public:
	SmallTree();

};

class MedTree : public TreeNode{

public:
	MedTree();

};

class LargeTree : public TreeNode{

public:
	LargeTree();

};

class RockNode{
protected:
	MapTile*** rock;
	int rockSize;

public:
	MapTile*** getRock(){ return rock; }
	int getRockSize(){ return rockSize; }

};

class SmallRock : public RockNode{
public:
	SmallRock();

};

class MedRock : public RockNode{
public:
	MedRock();

};

class LargeRock : public RockNode{
public:
	LargeRock();

};