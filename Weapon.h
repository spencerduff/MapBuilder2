#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Character;
class Keen;

enum Type { primary, quiver };
enum DamageType { slashing, piercing, bludgeoning, arrow };

class Weapon : public Item{
public:
	Weapon(Inventory* p);
	virtual ~Weapon();
	Weapon(const Weapon& rhs);

	Item* clone() override;

	void setName(string newName){ Item::setName(newName); }
	void setSymbol(char newSymbol){ Item::setSymbol(newSymbol); }
	void setWeight(float newWeight){ Item::setWeight(newWeight); }

	string equip(Character *c) override;
	string examine() override;

	void enchant(Enchant* e) override;
	void keen(Keen* k);
	void addToEnchantingTable(Thaumaturgy *t) override;

	void decrementDura(){ if (this->getName() != "Leafblade") this->dura -= .10; }

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
	void setSymbolOfWep(char symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }

};

class Shortsword : public Weapon{
public:
	Shortsword(Inventory* p);
	~Shortsword();

private:
	void setNameOfWep(string name){ setName(name); }
	void setSymbolOfWep(char symbol){ setSymbol(symbol); }
	void setWeightOfWep(float weight){ setWeight(weight); }


};


#endif