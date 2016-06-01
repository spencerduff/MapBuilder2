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
	void printInv();

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


	void printPaperdoll();
	void unequip(Item *a);

	void setHelm(Armor *h){ 
		if (helm != NULL)
			helm->equipped = false;
		helm = h;
		if (h == NULL) return;
		h->equipped = true;
		cout << "Helm set to: " << helm->getName() << endl;
	}
	void setChest(Armor *c){
		if (chest != NULL)
			chest->equipped = false;
		chest = c;
		if (c == NULL) return;
		c->equipped = true;
		cout << "Chest set to: " << chest->getName() << endl;
	}
	void setLegs(Armor *l){
		if (legs != NULL)
			legs->equipped = false;
		legs = l;
		if (l == NULL) return;
		l->equipped = true;
		cout << "Legs set to: " << legs->getName() << endl;
	}
	void setGreaves(Armor *g){
		if (greaves != NULL)
			greaves->equipped = false;
		greaves = g;
		if (g == NULL) return;
		g->equipped = true;
		cout << "Greaves set to: " << greaves->getName() << endl;
	}
	void setGauntlets(Armor *g){
		if (gauntlets != NULL)
			gauntlets->equipped = false;
		gauntlets = g;
		if (g == NULL) return;
		g->equipped = true;
		cout << "Gauntlets set to: " << gauntlets->getName() << endl;
	}
	void setElbows(Armor *e){
		if (elbows != NULL)
			elbows->equipped = false;
		elbows = e;
		if (e == NULL) return;
		e->equipped = true;
		cout << "Elbows set to: " << elbows->getName() << endl;
	}
	void setBoots(Armor *b){
		if (boots != NULL)
			boots->equipped = false;
		boots = b;
		if (b == NULL) return;
		b->equipped = true;
		cout << "Boots set to: " << boots->getName() << endl;
	}
	void setVambraces(Armor *v){
		if (vambraces != NULL)
			vambraces->equipped = false;
		vambraces = v;
		if (v == NULL) return;
		v->equipped = true;
		cout << "Vambraces set to: " << vambraces->getName() << endl;
	}
	void setGirdle(Armor *g){
		if (girdle != NULL)
			girdle->equipped = false;
		girdle = g;
		if (g == NULL) return;
		g->equipped = true;
		cout << "Girdle set to: " << girdle->getName() << endl;
	}
	void setShoulders(Armor *s){
		if (shoulders != NULL)
			shoulders->equipped = false;
		shoulders = s;
		if (s == NULL) return;
		s->equipped = true;
		cout << "Shoulders set to: " << shoulders->getName() << endl;
	}
	void setNecklace(Armor *n){
		if (necklace != NULL)
			necklace->equipped = false;
		necklace = n; 
		if (n == NULL) return;
		n->equipped = true;
		cout << "Necklace set to: " << necklace->getName() << endl;
	}
	void setRhRing(Armor *r){
		if (rhRing != NULL)
			rhRing->equipped = false;
		rhRing = r; 
		if (r == NULL) return;
		r->equipped = true;
		cout << "Right-Hand Ring set to: " << rhRing->getName() << endl;
	}
	void setLhRing(Armor *l){
		if (lhRing != NULL)
			lhRing->equipped = false;
		lhRing = l; 
		if (l == NULL) return;
		l->equipped = true;
		cout << "Left-Hand Ring set to: " << lhRing->getName() << endl;
	}
	void setEarring(Armor *e){
		if (earring != NULL)
			earring->equipped = false;
		earring = e; 
		if (e == NULL) return;
		e->equipped = true;
		cout << "Earring set to: " << earring->getName() << endl;
	}
	void setRobe(Armor *r){
		if (robe != NULL)
			robe->equipped = false;
		robe = r; 
		if (r == NULL) return;
		r->equipped = true;
		cout << "Robe set to: " << robe->getName() << endl;
		cout << "All other armor is taken off " << endl;
	}
	void setShield(Armor *s){
		if (shield != NULL)
			shield->equipped = false;
		shield = s; 
		if (s == NULL) return;
		s->equipped = true;
		cout << "Shield set to: " << shield->getName() << endl;
	}
	void setPrimary(Weapon *p){
		if (primary != NULL)
			primary->equipped = false;
		primary = p; 
		if (p == NULL) return;
		p->equipped = true;
		cout << "Primary set to: " << primary->getName() << endl;
	}
	void setQuiver(Weapon *q){
		if (quiver != NULL)
			quiver->equipped = false;
		quiver = q; 
		if (q == NULL) return;
		q->equipped = true;
		cout << "Quiver set to: " << quiver->getName() << endl;
	}


protected:

};

#endif