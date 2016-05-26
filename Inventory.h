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
		helm = h; 
		h->equipped = true;
		cout << "Helm set to: " << helm->getName() << endl;
	}
	void setChest(Armor *c){ 
		chest = c; 
		c->equipped = true;
		cout << "Chest set to: " << chest->getName() << endl;
	}
	void setLegs(Armor *l){ 
		legs = l; 
		l->equipped = true;
		cout << "Legs set to: " << legs->getName() << endl;
	}
	void setGreaves(Armor *g){ 
		greaves = g; 
		g->equipped = true;
		cout << "Greaves set to: " << greaves->getName() << endl;
	}
	void setGauntlets(Armor *g){ 
		gauntlets = g; 
		g->equipped = true;
		cout << "Gauntlets set to: " << gauntlets->getName() << endl;
	}
	void setElbows(Armor *e){ 
		elbows = e; 
		e->equipped = true;
		cout << "Elbows set to: " << elbows->getName() << endl;
	}
	void setBoots(Armor *b){ 
		boots = b; 
		b->equipped = true;
		cout << "Boots set to: " << boots->getName() << endl;
	}
	void setVambraces(Armor *v){ 
		vambraces = v; 
		v->equipped = true;
		cout << "Vambraces set to: " << vambraces->getName() << endl;
	}
	void setGirdle(Armor *g){ 
		girdle = g; 
		g->equipped = true;
		cout << "Girdle set to: " << girdle->getName() << endl;
	}
	void setShoulders(Armor *s){ 
		shoulders = s; 
		s->equipped = true;
		cout << "Shoulders set to: " << shoulders->getName() << endl;
	}
	void setNecklace(Armor *n){ 
		necklace = n; 
		n->equipped = true;
		cout << "Necklace set to: " << necklace->getName() << endl;
	}
	void setRhRing(Armor *r){ 
		rhRing = r; 
		r->equipped = true;
		cout << "Right-Hand Ring set to: " << rhRing->getName() << endl;
	}
	void setLhRing(Armor *l){ 
		lhRing = l; 
		l->equipped = true;
		cout << "Left-Hand Ring set to: " << lhRing->getName() << endl;
	}
	void setEarring(Armor *e){ 
		earring = e; 
		e->equipped = true;
		cout << "Earring set to: " << earring->getName() << endl;
	}
	void setRobe(Armor *r){ 
		robe = r; 
		r->equipped = true;
		cout << "Robe set to: " << robe->getName() << endl;
	}
	void setShield(Armor *s){ 
		shield = s; 
		s->equipped = true;
		cout << "Shield set to: " << shield->getName() << endl;
	}
	void setPrimary(Weapon *p){ 
		primary = p; 
		p->equipped = true;
		cout << "Primary set to: " << primary->getName() << endl;
	}
	void setQuiver(Weapon *q){ 
		quiver = q; 
		q->equipped = true;
		cout << "Quiver set to: " << quiver->getName() << endl;
	}


protected:

};

#endif