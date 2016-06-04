#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Character;
class Keen;
class Spell;
class Map;

enum Type { primary, quiver };
enum DamageType { slashing, piercing, bludgeoning, arrow, fire, indirect };

class Weapon : public Item{
public:
	Weapon(Inventory* p);
	virtual ~Weapon();
	Weapon(const Weapon& rhs);

	Item* clone() override;

	void setName(string newName){ Item::setName(newName); }
	void setSymbol(Symbol* newSymbol){ Item::setSymbol(newSymbol); }
	void setWeight(float newWeight){ Item::setWeight(newWeight); }

	void equip(Character *c) override;
	void examine() override;
	virtual void cast(Spell* s, Map* m);

	void enchant(Enchant* e) override;
	void keen(Keen* k);
	void addToEnchantingTable(Thaumaturgy *t) override;

	string decrementDura(){ 
		if (getName() != "Leafblade") dura -= .10;
		if (dura <= 0){
			delete this;
			return "An item has broken from use!\n";
		}
		return "";
	}

	float getDamage(){ 
		if (this == NULL)
			return 0;
		return damage; 
	}
	float getSpeed(){
		if (this == NULL)
			return 0; 
		return speed;
	}
	int getWeaponRank(){ 
		if (this == NULL)
			return 0;
		return weaponRank; 
	}
	DamageType getDamageType(){
		if (this == NULL)
			return slashing;
		return damageType;
	}

protected:
	Type type;
	float damage;
	float speed;
	float dura;
	float duraMax;
	string maker;
	int weaponRank;
	DamageType damageType;
	Enchant* enchantPrefix;
	Enchant* enchantSuffix;
};

class Leafblade : public Weapon{
public:
	Leafblade(Inventory* p);
	~Leafblade();

private:
	void setNameOfWep(string name){ setName(name); }
	void setSymbolOfWep(Symbol* symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }

};

class Shortsword : public Weapon{
public:
	Shortsword(Inventory* p);
	~Shortsword();

private:
	void setNameOfWep(string name){ setName(name); }
	void setSymbolOfWep(Symbol* symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }

};

class Staff : public Weapon{
public:
	Staff(Inventory* p) : Weapon(p){}
	void cast(Spell* s, Map* m) override;

private:
	
};

class TrollStaff : public Staff{
public:
	TrollStaff(Inventory* p);
	~TrollStaff(){}

private:
	void setNameOfWep(string name){ setName(name); }
	void setSymbolOfWep(Symbol* symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }
};


#endif