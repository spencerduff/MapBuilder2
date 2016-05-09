#include "Node.h"

SmallTree::SmallTree(){
	treeSizeX = 3;
	treeSizeY = 4;
	tree = new MapTile**[treeSizeX];

	for (int i = 0; i < treeSizeX; i++){
		tree[i] = new MapTile*[treeSizeY];
		for (int j = 0; j < treeSizeY; j++){
			if (j < 2){
				tree[i][j] = new MapTile('*');
			}
			else if (i == 1){
				tree[i][j] = new MapTile('|');
			}
			else{
				tree[i][j] = new MapTile('`');
			}
		}
	}

}

MedTree::MedTree(){
	treeSizeX = 4;
	treeSizeY = 6;
	tree = new MapTile**[treeSizeX];

	for (int i = 0; i < treeSizeX; i++){
		tree[i] = new MapTile*[treeSizeY];
		for (int j = 0; j < treeSizeY; j++){
			if (j < 3){
				tree[i][j] = new MapTile('*');
			}
			else if (i == 1 || i == 2){
				tree[i][j] = new MapTile('|');
			}
			else{
				tree[i][j] = new MapTile('`');
			}
		}
	}

}

LargeTree::LargeTree(){
	treeSizeX = 6;
	treeSizeY = 8;
	tree = new MapTile**[treeSizeX];

	for (int i = 0; i < treeSizeX; i++){
		tree[i] = new MapTile*[treeSizeY];
		for (int j = 0; j < treeSizeY; j++){
			if (j < 3){
				tree[i][j] = new MapTile('*');
			}
			else if (i >= 1 && i <= 4){
				tree[i][j] = new MapTile('|');
			}
			else{
				tree[i][j] = new MapTile('`');
			}
		}
	}

}