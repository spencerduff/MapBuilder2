#include "AI.h"

AI::AI(int p){
	m_perception = p;
}

void AI::tellOthers(){
	return;
}

bool AI::inPerception(int x, int y){
	if (abs(x - me->getXpos()) > m_perception || abs(y - me->getYpos()) > m_perception)
		return false;
	return true;
}

std::string AI::createPath(Character* toChar){
	int x = me->getXpos();
	int y = me->getYpos();
	int tolerance = m_perception * 2;
	std::string path = "";

	while ((x != toChar->getXpos() || y != toChar->getYpos()) && tolerance > 0){
		char nextMove = getNextMove(x, y, toChar->getXpos(), toChar->getYpos());
		path += nextMove;
		if (nextMove == 'y' || nextMove == 'b' || nextMove == 'h'){
			--x;
		}
		if (nextMove == 'u' || nextMove == 'n' || nextMove == 'l'){
			++x;
		}
		if (nextMove == 'y' || nextMove == 'u' || nextMove == 'k'){
			--y;
		}
		if (nextMove == 'j' || nextMove == 'b' || nextMove == 'n'){
			++y;
		}
		--tolerance;
	}

	return path;
}

char AI::getNextMove(int x, int y, int destX, int destY){
	//AI needs to move left and up
	if (destX - x < 0 && destY - y < 0){
		if (currMap->checkNotCollidableWithoutPChar(x - 1, y - 1)){
			return 'y';
		}
	}
	//AI needs to move left and down
	if (destX - x < 0 && destY - y > 0){
		if (currMap->checkNotCollidableWithoutPChar(x - 1, y + 1)){
			return 'b';
		}
	}
	//AI needs to move right and up
	if (destX - x > 0 && destY - y < 0){
		if (currMap->checkNotCollidableWithoutPChar(x + 1, y - 1)){
			return 'u';
		}
	}
	//AI needs to move right and down
	if (destX - x > 0 && destY - y > 0){
		if (currMap->checkNotCollidableWithoutPChar(x + 1, y + 1)){
			return 'n';
		}
	}
	//AI needs to move left
	if (destX - x < 0){
		if (currMap->checkNotCollidableWithoutPChar(x - 1, y)){
			return 'h';
		}
	}
	//AI needs to move right
	if (destX - x > 0){
		if (currMap->checkNotCollidableWithoutPChar(x + 1, y)){
			return 'l';
		}
	}
	//AI needs to move up
	if (destY - y < 0){
		if (currMap->checkNotCollidableWithoutPChar(x, y - 1)){
			return 'k';
		}
	}
	//AI needs to move down
	if (destY - y > 0){
		if (currMap->checkNotCollidableWithoutPChar(x, y + 1)){
			return 'j';
		}
	}

	//Call diagonals again in case there is an obstruction
	
	//AI needs to move left and up
	if (destX - x < 0 || destY - y < 0){
		if (currMap->checkNotCollidableWithoutPChar(x - 1, y - 1)){
			return 'y';
		}
	}
	//AI needs to move left and down
	if (destX - x < 0 || destY - y > 0){
		if (currMap->checkNotCollidableWithoutPChar(x - 1, y + 1)){
			return 'b';
		}
	}
	//AI needs to move right and up
	if (destX - x > 0 || destY - y < 0){
		if (currMap->checkNotCollidableWithoutPChar(x + 1, y - 1)){
			return 'u';
		}
	}
	//AI needs to move right and down
	if (destX - x > 0 || destY - y > 0){
		if (currMap->checkNotCollidableWithoutPChar(x + 1, y + 1)){
			return 'n';
		}
	}

	return ' ';
}


MeleeAI::MeleeAI(Map* iMap, Character* iChar, int p) : AI(p) {
	currMap = iMap;
	me = iChar;
	attacked = false;
}


void MeleeAI::move(){
	Character* pChar = currMap->getPlayerChar();

	if ((abs(pChar->getXpos() - me->getXpos()) > m_perception || abs(pChar->getYpos() - me->getYpos()) > m_perception) && attacked == false)
		return;
	//AI needs to move left and up
	if (pChar->getXpos() - me->getXpos() < 0 && pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() - 1, me->getYpos() - 1)){
			me->setMovement('y');
			return;
		}
	}
	//AI needs to move left and down
	if (pChar->getXpos() - me->getXpos() < 0 && pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() - 1, me->getYpos() + 1)){
			me->setMovement('b');
			return;
		}
	}
	//AI needs to move right and up
	if (pChar->getXpos() - me->getXpos() > 0 && pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() + 1, me->getYpos() - 1)){
			me->setMovement('u');
			return;
		}
	}
	//AI needs to move right and down
	if (pChar->getXpos() - me->getXpos() > 0 && pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() + 1, me->getYpos() + 1)){
			me->setMovement('n');
			return;
		}
	}
	//AI needs to move left
	if (pChar->getXpos() - me->getXpos() < 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() - 1, me->getYpos())){
			me->setMovement('h');
			return;
		}
	}
	//AI needs to move right
	if (pChar->getXpos() - me->getXpos() > 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() + 1, me->getYpos())){
			me->setMovement('l');
			return;
		}
	}
	//AI needs to move up
	if (pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos(), me->getYpos() - 1)){
			me->setMovement('k');
			return;
		}
	}
	//AI needs to move down
	if (pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos(), me->getYpos() + 1)){
			me->setMovement('j');
			return;
		}
	}

}

TalkingAI::TalkingAI(Map* iMap, Character* iChar, int p) : AI(p) {
	currMap = iMap;
	me = iChar;
	attacked = false;
}

void TalkingAI::move(){
	Character* pChar = currMap->getPlayerChar();

	if (attacked == false)
		return;
	attacked = false;
	//AI needs to move left and up
	if (pChar->getXpos() - me->getXpos() < 0 && pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() - 1, me->getYpos() - 1)){
			me->setMovement('y');
			return;
		}
	}
	//AI needs to move left and down
	if (pChar->getXpos() - me->getXpos() < 0 && pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() - 1, me->getYpos() + 1)){
			me->setMovement('b');
			return;
		}
	}
	//AI needs to move right and up
	if (pChar->getXpos() - me->getXpos() > 0 && pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() + 1, me->getYpos() - 1)){
			me->setMovement('u');
			return;
		}
	}
	//AI needs to move right and down
	if (pChar->getXpos() - me->getXpos() > 0 && pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() + 1, me->getYpos() + 1)){
			me->setMovement('n');
			return;
		}
	}
	//AI needs to move left
	if (pChar->getXpos() - me->getXpos() < 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() - 1, me->getYpos())){
			me->setMovement('h');
			return;
		}
	}
	//AI needs to move right
	if (pChar->getXpos() - me->getXpos() > 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos() + 1, me->getYpos())){
			me->setMovement('l');
			return;
		}
	}
	//AI needs to move up
	if (pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos(), me->getYpos() - 1)){
			me->setMovement('k');
			return;
		}
	}
	//AI needs to move down
	if (pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidableMapTile(me->getXpos(), me->getYpos() + 1)){
			me->setMovement('j');
			return;
		}
	}
	attacked = false;
}

MediumSmartAI::MediumSmartAI(Map* iMap, Character* iChar, int p) : AI(p){
	currMap = iMap;
	me = iChar;
	attacked = false;
}

void MediumSmartAI::move(){
	Character* pChar = currMap->getPlayerChar();
	if ((abs(pChar->getXpos() - me->getXpos()) > m_perception || abs(pChar->getYpos() - me->getYpos()) > m_perception) && attacked == false)
		return;
	std::string p = createPath(pChar);
	if (p.length() > 0){
		me->setMovement(p[0]);
	}
}

SmartAI::SmartAI(Map* iMap, Character* iChar, int p) : AI(p){
	currMap = iMap;
	me = iChar;
	attacked = false;
}

void SmartAI::move(){
	Character* pChar = currMap->getPlayerChar();
	if ((abs(pChar->getXpos() - me->getXpos()) > m_perception || abs(pChar->getYpos() - me->getYpos()) > m_perception) && attacked == false)
		return;
	tellOthers();
	std::string p = createPath(pChar);
	if (p.length() > 0){
		me->setMovement(p[0]);
	}
}

void SmartAI::tellOthers(){
	setAttacked();
	for (unsigned int i = 1; i < currMap->chars.size(); ++i){
		if (inPerception(currMap->chars[i]->getXpos(), currMap->chars[i]->getYpos())){
			if (!currMap->chars[i]->getAI()->isAttacked()){
				currMap->chars[i]->getAI()->tellOthers();
			}
		}
	}
}