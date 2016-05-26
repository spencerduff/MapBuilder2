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
		helm = h;
		if (h == NULL) return "";
		h->equipped = true;
		ss << "Helm set to: " << helm->getName() << endl;
		return ss.str();
	}
	string setChest(Armor *c){
		stringstream ss;
		chest = c;
		if (c == NULL) return "";
		c->equipped = true;
		ss << "Chest set to: " << chest->getName() << endl;
		return ss.str();
	}
	string setLegs(Armor *l){
		stringstream ss;
		legs = l;
		if (l == NULL) return "";
		l->equipped = true;
		ss << "Legs set to: " << legs->getName() << endl;
		return ss.str();
	}
	string setGreaves(Armor *g){
		stringstream ss;
		greaves = g;
		if (g == NULL) return "";
		g->equipped = true;
		ss << "Greaves set to: " << greaves->getName() << endl;
		return ss.str();
	}
	string setGauntlets(Armor *g){
		stringstream ss;
		gauntlets = g;
		if (g == NULL) return "";
		g->equipped = true;
		ss << "Gauntlets set to: " << gauntlets->getName() << endl;
		return ss.str();
	}
	string setElbows(Armor *e){
		stringstream ss;
		elbows = e;
		if (e == NULL) return "";
		e->equipped = true;
		ss << "Elbows set to: " << elbows->getName() << endl;
		return ss.str();
	}
	string setBoots(Armor *b){
		stringstream ss;
		boots = b;
		if (b == NULL) return "";
		b->equipped = true;
		ss << "Boots set to: " << boots->getName() << endl;
		return ss.str();
	}
	string setVambraces(Armor *v){
		stringstream ss;
		vambraces = v;
		if (v == NULL) return "";
		v->equipped = true;
		ss << "Vambraces set to: " << vambraces->getName() << endl;
		return ss.str();
	}
	string setGirdle(Armor *g){
		stringstream ss;
		girdle = g;
		if (g == NULL) return "";
		g->equipped = true;
		ss << "Girdle set to: " << girdle->getName() << endl;
		return ss.str();
	}
	string setShoulders(Armor *s){
		stringstream ss;
		shoulders = s;
		if (s == NULL) return "";
		s->equipped = true;
		ss << "Shoulders set to: " << shoulders->getName() << endl;
		return ss.str();
	}
	string setNecklace(Armor *n){
		stringstream ss;
		necklace = n; 
		n->equipped = true;
		ss << "Necklace set to: " << necklace->getName() << endl;
		return ss.str();
	}
	string setRhRing(Armor *r){
		stringstream ss;
		rhRing = r; 
		r->equipped = true;
		ss << "Right-Hand Ring set to: " << rhRing->getName() << endl;
		return ss.str();
	}
	string setLhRing(Armor *l){
		stringstream ss;
		lhRing = l; 
		l->equipped = true;
		ss << "Left-Hand Ring set to: " << lhRing->getName() << endl;
		return ss.str();
	}
	string setEarring(Armor *e){
		stringstream ss;
		earring = e; 
		e->equipped = true;
		ss << "Earring set to: " << earring->getName() << endl;
		return ss.str();
	}
	string setRobe(Armor *r){
		stringstream ss;
		robe = r; 
		r->equipped = true;
		ss << "Robe set to: " << robe->getName() << endl;
		ss << "All other armor is taken off " << endl;
		return ss.str();
	}
	string setShield(Armor *s){
		stringstream ss;
		shield = s; 
		s->equipped = true;
		ss << "Shield set to: " << shield->getName() << endl;
		return ss.str();
	}
	string setPrimary(Weapon *p){
		stringstream ss;
		primary = p; 
		p->equipped = true;
		ss << "Primary set to: " << primary->getName() << endl;
		return ss.str();
	}
	string setQuiver(Weapon *q){
		stringstream ss;
		quiver = q; 
		q->equipped = true;
		ss << "Quiver set to: " << quiver->getName() << endl;
		return ss.str();
	}


protected:

};

#endif