#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Character;
class Keen;
class Spell;
class Map;

enum Type { primary, quiver };
enum DamageType { slashing, piercing, bludgeoning, arrow, fire, indirect };

// Weapon is a type of Item that can be equipped to the primary or quiver of a Paperdoll. Used for fighting.
class Weapon : public Item{
public:
	Weapon(Inventory* p);
	virtual ~Weapon();
	Weapon(const Weapon& rhs);
	// Used for looting from a Gravestone
	Item* clone() override;

	// Setters
	void setName(string newName){ Item::setName(newName); }
	void setSymbol(Symbol* newSymbol){ Item::setSymbol(newSymbol); }
	void setWeight(float newWeight){ Item::setWeight(newWeight); }

	// Equips the Weapon to the correct slot on the Paperdoll of a Character
	void equip(Character *c) override;
	// Prints information of a Weapon
	void examine() override;
	// Cast for the subclass Staff
	virtual void cast(Spell* s, Map* m);

	// Enchanting a Weapon is different from Armor or Staff
	void enchant(Enchant* e) override;
	// Keens a Weapon, or if a Staff, fails the Enchant
	virtual void keen(Keen* k);
	// Adds it to the Item slot of a Thaumaturgy
	void addToEnchantingTable(Thaumaturgy *t) override;

	string decrementDura(){ 
		if (getName() != "Leafblade") dura -= .10;
		if (dura <= 0){
			delete this;
			return "A weapon has broken from use!\n";
		}
		return "";
	}

	// Getters
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
	// Cast function for spells. Spells can be cast when wielding a Staff
	void cast(Spell* s, Map* m) override;
	// Fails a keen enchant on a staff.
	void keen(Keen* k) override;

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