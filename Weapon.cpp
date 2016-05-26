#include "Weapon.h"
#include "Character.h"
#include <iomanip>

Weapon::Weapon() : Item(){}

Weapon::~Weapon(){

}

void Weapon::equip(Character *c){
	if (this->type == primary)
		c->getPaperdoll()->setPrimary(this);
	else if (this->type == quiver)
		c->getPaperdoll()->setQuiver(this);
}

void Weapon::examine(){
	cout << getName() << endl;
	cout << getSymbol() << endl;
	cout << "Weight: " << setprecision(2) << fixed << getWeight() << endl;
	cout << "Damage: ";
	cout << setprecision(2) << fixed << damage << endl;
	cout << "Speed: ";
	cout << setprecision(2) << fixed << speed << endl;
	cout << "Durability: ";
	cout << setprecision(2) << fixed << dura << "/" << setprecision(2) << fixed << duraMax << endl;
	cout << "Maker: " << maker << endl;
	cout << "Weapon Rank: " << weaponRank << endl;
	cout << "Type: ";
	if (type == primary)
		cout << "Primary" << endl;
	else
		cout << "Quiver" << endl;
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

