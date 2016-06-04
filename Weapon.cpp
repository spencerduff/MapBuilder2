#include "Weapon.h"
#include "Character.h"
#include <iomanip>
#include "Enchants.h"

Weapon::Weapon(Inventory* p) : Item(p){}

Weapon::~Weapon(){
	delete enchantPrefix;
	delete enchantSuffix;
	enchantPrefix = NULL;
	enchantSuffix = NULL;
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

void Weapon::equip(Character *c){
	if (this->type == primary)
		c->getPaperdoll()->setPrimary(this);
	else if (this->type == quiver)
		c->getPaperdoll()->setQuiver(this);
}

void Weapon::examine(){
	cout << getName() << endl;
	getSymbol()->printSymbol();
	cout << endl;
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
		string a = "of Keenecout";
		setName(getName() += a);
	}
}

void Weapon::addToEnchantingTable(Thaumaturgy *t){
	t->setToEnchant(this);
}

void Weapon::cast(Spell* s, Map* m){
	cout << "You must equip a staff to cast a spell. " << endl;
}

Leafblade::Leafblade(Inventory* p) : Weapon(p){
	setName("Leafblade");
	setWeight(0.0);
	setSymbol(new Symbol('/', 2));
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
	setSymbol(new Symbol('/', 8));
	damage = 0.31;
	speed = 0.6;
	duraMax = 51.00;
	dura = (rand() % (int)duraMax) + 1.0;
	maker = "The World";
	weaponRank = 0;
	setItemID(getNextID());
	type = primary;
	damageType = slashing;
	equipped = false;
}

Shortsword::~Shortsword(){

}

void Staff::cast(Spell* s, Map* m){
	if (s == NULL)
		return;
	s->cast(damage, m);
}

TrollStaff::TrollStaff(Inventory* p) : Staff(p){
	setName("Troll Staff");
	setWeight(1.0);
	setSymbol(new Symbol('_', 6));
	damage = 0.00;
	speed = 0.5;
	duraMax = 51.00;
	dura = (rand() % (int)duraMax) + 1.0;
	maker = "The World";
	weaponRank = 0;
	setItemID(getNextID());
	type = primary;
	damageType = indirect;
	equipped = false;

}
