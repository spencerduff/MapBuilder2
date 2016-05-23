#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Armor.h"
#include "Weapon.h"
#include <iostream>

class Inventory{
public:
	Inventory();
	vector<Item*> inventory;
	void printInv();

protected:
	

};

class Paperdoll{
public:
	
	Paperdoll();
	void printPaperdoll();
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


	void unequip(Item *a);
	void setHelm(Armor *h){ 
		helm = h; 
		h->equipped = true;
		cout << "Helm set to: " << helm->name << endl;
	}
	void setChest(Armor *c){ 
		chest = c; 
		c->equipped = true;
		cout << "Chest set to: " << chest->name << endl;
	}
	void setLegs(Armor *l){ 
		legs = l; 
		l->equipped = true;
		cout << "Legs set to: " << legs->name << endl;
	}
	void setGreaves(Armor *g){ 
		greaves = g; 
		g->equipped = true;
		cout << "Greaves set to: " << greaves->name << endl;
	}
	void setGauntlets(Armor *g){ 
		gauntlets = g; 
		g->equipped = true;
		cout << "Gauntlets set to: " << gauntlets->name << endl;
	}
	void setElbows(Armor *e){ 
		elbows = e; 
		e->equipped = true;
		cout << "Elbows set to: " << elbows->name << endl;
	}
	void setBoots(Armor *b){ 
		boots = b; 
		b->equipped = true;
		cout << "Boots set to: " << boots->name << endl;
	}
	void setVambraces(Armor *v){ 
		vambraces = v; 
		v->equipped = true;
		cout << "Vambraces set to: " << vambraces->name << endl;
	}
	void setGirdle(Armor *g){ 
		girdle = g; 
		g->equipped = true;
		cout << "Girdle set to: " << girdle->name << endl;
	}
	void setShoulders(Armor *s){ 
		shoulders = s; 
		s->equipped = true;
		cout << "Shoulders set to: " << shoulders->name << endl;
	}
	void setNecklace(Armor *n){ 
		necklace = n; 
		n->equipped = true;
		cout << "Necklace set to: " << necklace->name << endl;
	}
	void setRhRing(Armor *r){ 
		rhRing = r; 
		r->equipped = true;
		cout << "Right-Hand Ring set to: " << rhRing->name << endl;
	}
	void setLhRing(Armor *l){ 
		lhRing = l; 
		l->equipped = true;
		cout << "Left-Hand Ring set to: " << lhRing->name << endl;
	}
	void setEarring(Armor *e){ 
		earring = e; 
		e->equipped = true;
		cout << "Earring set to: " << earring->name << endl;
	}
	void setRobe(Armor *r){ 
		robe = r; 
		r->equipped = true;
		cout << "Robe set to: " << robe->name << endl;
	}
	void setShield(Armor *s){ 
		shield = s; 
		s->equipped = true;
		cout << "Shield set to: " << shield->name << endl;
	}
	void setPrimary(Weapon *p){ 
		primary = p; 
		p->equipped = true;
		cout << "Primary set to: " << primary->name << endl;
	}
	void setQuiver(Weapon *q){ 
		quiver = q; 
		q->equipped = true;
		cout << "Quiver set to: " << quiver->name << endl;
	}


protected:

};

#endif