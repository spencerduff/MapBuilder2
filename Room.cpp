#include "Room.h"

Room::Room(){
	numPorts = (rand() % 4) + 1;
	size = (rand() % (maxSize - minSize)) + minSize;
	board = new MapTile**[size];
	for (int i = 0; i < size; i++){
		board[i] = new MapTile*[size];
		for (int j = 0; j < size; ++j){
			board[i][j] = new MapTile();
		}
	}
	

}

void Room::makeWalls(){
	//If it's on the border, give a wall, otherwise, give it empty floor
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1){
				board[i][j]->setGroundTile(new Symbol('#', 8));
			}
			else{
				board[i][j]->setGroundTile(new Symbol('.', 8));
			}

		}
	}
}

//TODO: Make sure door doesn't face a wall, if there is only 1 door (Rarely if there is two)
//Maybe unecessary
void Room::addPorts(){
	for (int i = 0; i < size; i++){
		int portsToGo = numPorts;
		int iter = 0;
		bool leftSide = false;
		bool rightSide = false;
		bool topSide = false;
		bool bottomSide = false;
		while (portsToGo > 0){
			//Make iter not in a corner
			iter = (rand() % (size - 2)) + 1;
			//Checks if there is a door already on that side, then if it's that side's
			//turn, then if it passes a random check, so that one side isn't favored for
			//having doors.
			for (int i = 0; i < 4; i++){
				if (!leftSide && i == 0 && rand() % (size * 4 / numPorts) == 0){
					board[0][iter]->setGroundTile(new Symbol('+'));
					leftSide = true;
					portsToGo--;
					if (portsToGo == 0)
						return;
				}
				if (!rightSide && i == 1 && rand() % (size * 4 / numPorts) == 0){
					board[size - 1][iter]->setGroundTile(new Symbol('+'));
					rightSide = true;
					portsToGo--;
					if (portsToGo == 0)
						return;
				}
				if (!topSide && i == 2 && rand() % (size * 4 / numPorts) == 0){
					board[iter][0]->setGroundTile(new Symbol('+'));
					topSide = true;
					portsToGo--;
					if (portsToGo == 0)
						return;
				}
				if (!bottomSide && i == 3 && rand() % (size * 4 / numPorts) == 0){
					board[iter][size - 1]->setGroundTile(new Symbol('+'));
					bottomSide = true;
					portsToGo--;
					if (portsToGo == 0)
						return;
				}
			}
		}
	}
}

void Room::printRoom(){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << board[i][j]->getShowingTile();
		}
		cout << endl;
	}
	cout << endl;
}

void makeDiagonalRight(MapTile*** &board, int size, int mid, int y = 0){
	if (mid == size){
		mid = size - 1;
		while (y < size){
			board[mid][y++]->setGroundTile(new Symbol('#', 8));
		}
		return;
	}
	board[mid][y]->setGroundTile(new Symbol('#', 8));
	makeDiagonalRight(board, size, ++mid, ++y);
}

void makeDiagonalLeft(MapTile*** &board, int size, int mid, int y = 0){
	if (mid < 0){
		mid = 0;
		while (y < size){
			board[mid][y++]->setGroundTile(new Symbol('#', 8));
		}
		return;
	}
	board[mid][y]->setGroundTile(new Symbol('#', 8));
	makeDiagonalLeft(board, size, --mid, ++y);
}

void makeDiagonal(MapTile*** &board, int size){
	makeDiagonalLeft(board, size, size / 2);
	makeDiagonalRight(board, size, size / 2);
}

void OrkRoom::makeWalls(){
	//If it's on the border, give a wall, otherwise, give it empty floor
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (j == size - 1){
				board[i][j]->setGroundTile(new Symbol('#', 8));
			}
			else{
				board[i][j]->setGroundTile(new Symbol('.', 8));
			}
		}
	}
	makeDiagonal(board, size);
}

void OrkRoom::addPorts(){
	int pos = rand() % size;
	if (pos == 0)
		pos++;
	if (pos == size - 1)
		pos--;
	board[pos][size - 1]->setGroundTile(new Symbol('+'));
}

OrkRoom::OrkRoom() : Room(){
	numPorts = 1;

	//always odd number for good diagonals
	if (size % 2 == 0)
		size--;

	
	makeWalls();
	
	addPorts();

}

HumanRoom::HumanRoom() : Room(){

	makeWalls();

	addPorts();
}