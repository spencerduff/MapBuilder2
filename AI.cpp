#include "AI.h"

MeleeAI::MeleeAI(Map* iMap, Character* iChar){
	currMap = iMap;
	me = iChar;
	attacked = false;
}


void MeleeAI::move(){
	Character* pChar = currMap->getPlayerChar();

	if ((abs(pChar->getXpos() - me->getXpos()) > 10 || abs(pChar->getYpos() - me->getYpos()) > 10) && attacked == false )
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

TalkingAI::TalkingAI(Map* iMap, Character* iChar){
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