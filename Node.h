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