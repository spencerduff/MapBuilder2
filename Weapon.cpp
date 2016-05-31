#include "Weapon.h"
#include "Character.h"
#include <iomanip>
#include "Enchants.h"

Weapon::Weapon(Inventory* p) : Item(p){}

Weapon::~Weapon(){

}

Weapon::Weapon(const Weapon& rhs) : Item(rhs){
	this->type = rhs.type;
	this->damage = rhs.damage;
	this->speed = rhs.speed;
	this->dura = rhs.dura;
	this->duraMax = rhs.duraMax;
	this->maker = rhs.maker;
	this->weaponRank = rhs.weaponRank;
	this->damageType = rhs.damageType;
}

Item* Weapon::clone(){
	return new Weapon(*this);
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

void Weapon::enchant(Enchant* e){
	e->enchant(this);
}

void Weapon::keen(Keen* k){
	if (enchantPrefix == NULL){
		enchantPrefix = k;
		damage += k->getDmgMod();
		string a = "Keen ";
		a += getName();
		setName(a);
	}
	else if (enchantSuffix == NULL && enchantPrefix->getName() != "Keen"){
		enchantSuffix = k;
		damage += k->getDmgMod();
		string a = "of Keeness";
		setName(getName() += a);
	}
}

void Weapon::addToEnchantingTable(Thaumaturgy *t){
	t->setToEnchant(this);
}

Leafblade::Leafblade(Inventory* p) : Weapon(p){
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

Shortsword::Shortsword(Inventory* p) : Weapon(p){
	setName("Short Sword");
	setWeight(1.0);
	setSymbol('/');
	damage = 0.31;
	speed = 0.6;
	duraMax = 51.00;
	dura = rand() % (int)duraMax;
	maker = "The World";
	weaponRank = 0;
	setItemID(getNextID());
	type = primary;
	damageType = slashing;
	equipped = false;
}

Shortsword::~Shortsword(){

}
