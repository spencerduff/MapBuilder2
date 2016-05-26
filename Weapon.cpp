#include "Weapon.h"
#include "Character.h"
#include <iomanip>

Weapon::Weapon() : Item(){}

Weapon::~Weapon(){

}

string Weapon::equip(Character *c){
	stringstream ss;
	if (this->type == primary)
		ss << c->getPaperdoll()->setPrimary(this);
	else if (this->type == quiver)
		ss << c->getPaperdoll()->setQuiver(this);
	return ss.str();
}

string Weapon::examine(){
	stringstream ss;
	ss << getName() << endl;
	ss << getSymbol() << endl;
	ss << "Weight: " << setprecision(2) << fixed << getWeight() << endl;
	ss << "Damage: ";
	ss << setprecision(2) << fixed << damage << endl;
	ss << "Speed: ";
	ss << setprecision(2) << fixed << speed << endl;
	ss << "Durability: ";
	ss << setprecision(2) << fixed << dura << "/" << setprecision(2) << fixed << duraMax << endl;
	ss << "Maker: " << maker << endl;
	ss << "Weapon Rank: " << weaponRank << endl;
	ss << "Type: ";
	if (type == primary)
		ss << "Primary" << endl;
	else
		ss << "Quiver" << endl;
	return ss.str();
}

Leafblade::Leafblade() : Weapon(){
	setName("Leafblade");
	setWeight(0.0);
	setSymbol('/');
	damage = 0.26;
	speed = 0.6;
	duraMax = 999.00;
	dura = duraMax;
	maker = "The World";
	weaponRank = 0;
	setItemID(getNextID());
	type = primary;
	damageType = slashing;
	equipped = false;
}

Leafblade::~Leafblade(){

}

