#include "AI.h"

MeleeAI::MeleeAI(Map* iMap, Character* iChar){
	currMap = iMap;
	me = iChar;
}


void MeleeAI::move(){
	Character* pChar = currMap->getPlayerChar();

	if (abs(pChar->getXpos() - me->getXpos()) > 10 || abs(pChar->getYpos() - me->getYpos()) > 10)
		return;
	//AI needs to move left and up
	if (pChar->getXpos() - me->getXpos() < 0 && pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidable(me->getXpos() - 1, me->getYpos() - 1)){
			me->setMovement('y');
			return;
		}
	}
	//AI needs to move left and down
	if (pChar->getXpos() - me->getXpos() < 0 && pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidable(me->getXpos() - 1, me->getYpos() + 1)){
			me->setMovement('b');
			return;
		}
	}
	//AI needs to move right and up
	if (pChar->getXpos() - me->getXpos() > 0 && pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidable(me->getXpos() + 1, me->getYpos() - 1)){
			me->setMovement('u');
			return;
		}
	}
	//AI needs to move right and down
	if (pChar->getXpos() - me->getXpos() > 0 && pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidable(me->getXpos() + 1, me->getYpos() + 1)){
			me->setMovement('n');
			return;
		}
	}
	//AI needs to move left
	if (pChar->getXpos() - me->getXpos() < 0){
		if (currMap->checkNotCollidable(me->getXpos() - 1, me->getYpos())){
			me->setMovement('h');
			return;
		}
	}
	//AI needs to move right
	if (pChar->getXpos() - me->getXpos() > 0){
		if (currMap->checkNotCollidable(me->getXpos() + 1, me->getYpos())){
			me->setMovement('l');
			return;
		}
	}
	//AI needs to move up
	if (pChar->getYpos() - me->getYpos() < 0){
		if (currMap->checkNotCollidable(me->getXpos(), me->getYpos() - 1)){
			me->setMovement('k');
			return;
		}
	}
	//AI needs to move down
	if (pChar->getYpos() - me->getYpos() > 0){
		if (currMap->checkNotCollidable(me->getXpos(), me->getYpos() + 1)){
			me->setMovement('j');
			return;
		}
	}

}