#include "MapTile.h"

bool MapTile::isGroundTile(){
	if (showingTile->getSymbol() == '#' || showingTile->getSymbol() == '|' || showingTile->getSymbol() == '_' ||
		showingTile->getSymbol() == '`' || showingTile->getSymbol() == '~' || showingTile->getSymbol() == '+' || showingTile->getSymbol() == '^' ||
		showingTile->getSymbol() == '>' || showingTile->getSymbol() == 'v' || showingTile->getSymbol() == '<')
		return true;
	else return false;
}

MapTile::MapTile(){
	groundTile = NULL;
	showingTile = NULL;
}

MapTile::MapTile(int x, int y){
	groundTile = NULL;
	showingTile = NULL;
	posX = x;
	posY = y;
}

MapTile::MapTile(Symbol* gTile){
	groundTile = gTile;
	showingTile = groundTile;
}

Symbol *groundTile;
Symbol *showingTile;
vector<Symbol*> underTiles;

MapTile::~MapTile(){
	for (auto it = underTiles.begin(); it != underTiles.end() && underTiles.size() > 1; ++it){
		delete (*it);
		*it = nullptr;
	}
	underTiles.clear();
	if (groundTile != nullptr){
		delete groundTile;
		groundTile = nullptr;
	}
}

void MapTile::setGroundTile(Symbol* gTile){
	groundTile = gTile;
	if (showingTile == NULL || isGroundTile()){
		showingTile = groundTile;
	}
}

void MapTile::updateTile(Symbol* sTile){
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
	refresh();
}

void MapTile::refresh(){
	COORD pos = { posX + 1, posY + 1 };
	COORD posReturn = { 0, 52 };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
	cout << '\b';
	cout << *showingTile;
	SetConsoleCursorPosition(output, posReturn);
}

void MapTile::printTile(){
	cout << showingTile;
}

void MapTile::clearGraves(){
	for (unsigned int i = 0; i < underTiles.size(); i++){
		if (underTiles[i]->getSymbol() == '&'){
			underTiles.erase(underTiles.begin() + i);
		}
	}
}

void MapTile::removeChar(Symbol* c){
	for (unsigned int i = 0; i < underTiles.size(); i++){
		if (underTiles[i] == c){
			underTiles.erase(underTiles.begin() + i);
		}
	}
}