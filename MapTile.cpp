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
	if (sTile != NULL)
		showingTile = sTile;
	else showingTile = groundTile;
}

void MapTile::printTile(){
	cout << showingTile;
}