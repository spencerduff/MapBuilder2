#include "MapTile.h"

bool MapTile::isGroundTile(){
	if (showingTile == '#' || showingTile == '|' || showingTile == '_' ||
		showingTile == '`' || showingTile == '~' || showingTile == '+' || showingTile == '^' || 
		showingTile == '>' || showingTile == 'v' || showingTile == '<')
		return true;
	else return false;
}

MapTile::MapTile(){
	groundTile = NULL;
	showingTile = NULL;
}

MapTile::MapTile(char gTile){
	groundTile = gTile;
	showingTile = groundTile;
}

void MapTile::setGroundTile(char gTile){
	groundTile = gTile;
	if (showingTile == NULL || isGroundTile()){
		showingTile = groundTile;
	}
}

void MapTile::updateTile(char sTile){
	if (sTile != NULL){
		showingTile = sTile;
		underTiles.push_back(sTile);
	}
	else if (!underTiles.empty()){
		underTiles.pop_back();
		if (!underTiles.empty())
			showingTile = underTiles.back();
		else showingTile = groundTile;
	}
	else showingTile = groundTile;
}

void MapTile::printTile(){
	cout << showingTile;
}

void MapTile::clearGraves(){
	for (int i = 0; i < underTiles.size(); i++){
		if (underTiles[i] == '&'){
			underTiles.erase(underTiles.begin() + i);
		}
	}
}

void MapTile::removeChar(char c){
	for (int i = 0; i < underTiles.size(); i++){
		if (underTiles[i] == c){
			underTiles.erase(underTiles.begin() + i);
		}
	}
}