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

	void setHelm(Armor *h){ helm = h; }
	void setChest(Armor *c){ chest = c; }
	void setLegs(Armor *l){ legs = l; }
	void setGreaves(Armor *g){ greaves = g; }
	void setGauntlets(Armor *g){ gauntlets = g; }
	void setElbows(Armor *e){ elbows = e; }
	void setBoots(Armor *b){ boots = b; }
	void setVambraces(Armor *v){ vambraces = v; }
	void setGirdle(Armor *g){ girdle = g; }
	void setShoulders(Armor *s){ shoulders = s; }
	void setNecklace(Armor *n){ necklace = n; }
	void setRhRing(Armor *r){ rhRing = r; }
	void setLhRing(Armor *l){ lhRing = l; }
	void setEarring(Armor *e){ earring = e; }
	void setRobe(Armor *r){ robe = r; }
	void setShield(Armor *s){ shield = s; }
	void setPrimary(Weapon *p){ 
		primary = p; 
		cout << "Primary Set to: " << primary->name << endl;
	}
	void setQuiver(Weapon *q){ quiver = q; }


protected:

};

#endif