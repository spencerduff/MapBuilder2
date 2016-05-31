#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Armor.h"
#include "Weapon.h"
#include <iostream>

class Inventory{
public:
	Inventory();
	~Inventory();

	vector<Item*> inventory;
	string printInv();

	int parsePosInBackpack(char input);

	void removeItem(Item* item);

protected:
	

};

class Paperdoll{
public:
	
	Paperdoll();
	~Paperdoll();

	Armor *helm;
	Armor *chest;
	Armor *legs;
	Armor *greaves;
	Armor *gauntlets;
	Armor *elbows;
	Armor *boots;
	Armor *vambraces;
	Armor *girdle;
	Armor *shoulders;
	Armor *necklace;
	Armor *rhRing;
	Armor *lhRing;
	Armor *earring;
	Armor *robe;
	Armor *shield;
	Weapon *primary;
	Weapon *quiver;


	string printPaperdoll();
	void unequip(Item *a);

	string setHelm(Armor *h){ 
		stringstream ss;
		if (helm != NULL)
			helm->equipped = false;
		helm = h;
		if (h == NULL) return "";
		h->equipped = true;
		ss << "Helm set to: " << helm->getName() << endl;
		return ss.str();
	}
	string setChest(Armor *c){
		stringstream ss;
		if (chest != NULL)
			chest->equipped = false;
		chest = c;
		if (c == NULL) return "";
		c->equipped = true;
		ss << "Chest set to: " << chest->getName() << endl;
		return ss.str();
	}
	string setLegs(Armor *l){
		stringstream ss;
		if (legs != NULL)
			legs->equipped = false;
		legs = l;
		if (l == NULL) return "";
		l->equipped = true;
		ss << "Legs set to: " << legs->getName() << endl;
		return ss.str();
	}
	string setGreaves(Armor *g){
		stringstream ss;
		if (greaves != NULL)
			greaves->equipped = false;
		greaves = g;
		if (g == NULL) return "";
		g->equipped = true;
		ss << "Greaves set to: " << greaves->getName() << endl;
		return ss.str();
	}
	string setGauntlets(Armor *g){
		stringstream ss;
		if (gauntlets != NULL)
			gauntlets->equipped = false;
		gauntlets = g;
		if (g == NULL) return "";
		g->equipped = true;
		ss << "Gauntlets set to: " << gauntlets->getName() << endl;
		return ss.str();
	}
	string setElbows(Armor *e){
		stringstream ss;
		if (elbows != NULL)
			elbows->equipped = false;
		elbows = e;
		if (e == NULL) return "";
		e->equipped = true;
		ss << "Elbows set to: " << elbows->getName() << endl;
		return ss.str();
	}
	string setBoots(Armor *b){
		stringstream ss;
		if (boots != NULL)
			boots->equipped = false;
		boots = b;
		if (b == NULL) return "";
		b->equipped = true;
		ss << "Boots set to: " << boots->getName() << endl;
		return ss.str();
	}
	string setVambraces(Armor *v){
		stringstream ss;
		if (vambraces != NULL)
			vambraces->equipped = false;
		vambraces = v;
		if (v == NULL) return "";
		v->equipped = true;
		ss << "Vambraces set to: " << vambraces->getName() << endl;
		return ss.str();
	}
	string setGirdle(Armor *g){
		stringstream ss;
		if (girdle != NULL)
			girdle->equipped = false;
		girdle = g;
		if (g == NULL) return "";
		g->equipped = true;
		ss << "Girdle set to: " << girdle->getName() << endl;
		return ss.str();
	}
	string setShoulders(Armor *s){
		stringstream ss;
		if (shoulders != NULL)
			shoulders->equipped = false;
		shoulders = s;
		if (s == NULL) return "";
		s->equipped = true;
		ss << "Shoulders set to: " << shoulders->getName() << endl;
		return ss.str();
	}
	string setNecklace(Armor *n){
		stringstream ss;
		if (necklace != NULL)
			necklace->equipped = false;
		necklace = n; 
		n->equipped = true;
		ss << "Necklace set to: " << necklace->getName() << endl;
		return ss.str();
	}
	string setRhRing(Armor *r){
		stringstream ss;
		if (rhRing != NULL)
			rhRing->equipped = false;
		rhRing = r; 
		r->equipped = true;
		ss << "Right-Hand Ring set to: " << rhRing->getName() << endl;
		return ss.str();
	}
	string setLhRing(Armor *l){
		stringstream ss;
		if (lhRing != NULL)
			lhRing->equipped = false;
		lhRing = l; 
		l->equipped = true;
		ss << "Left-Hand Ring set to: " << lhRing->getName() << endl;
		return ss.str();
	}
	string setEarring(Armor *e){
		stringstream ss;
		if (earring != NULL)
			earring->equipped = false;
		earring = e; 
		e->equipped = true;
		ss << "Earring set to: " << earring->getName() << endl;
		return ss.str();
	}
	string setRobe(Armor *r){
		stringstream ss;
		if (robe != NULL)
			robe->equipped = false;
		robe = r; 
		r->equipped = true;
		ss << "Robe set to: " << robe->getName() << endl;
		ss << "All other armor is taken off " << endl;
		return ss.str();
	}
	string setShield(Armor *s){
		stringstream ss;
		if (shield != NULL)
			shield->equipped = false;
		shield = s; 
		s->equipped = true;
		ss << "Shield set to: " << shield->getName() << endl;
		return ss.str();
	}
	string setPrimary(Weapon *p){
		stringstream ss;
		if (primary != NULL)
			primary->equipped = false;
		primary = p; 
		p->equipped = true;
		ss << "Primary set to: " << primary->getName() << endl;
		return ss.str();
	}
	string setQuiver(Weapon *q){
		stringstream ss;
		if (quiver != NULL)
			quiver->equipped = false;
		quiver = q; 
		q->equipped = true;
		ss << "Quiver set to: " << quiver->getName() << endl;
		return ss.str();
	}


protected:

};

#endif