#include "Item.h"

class Armor : public Item{
public:

protected:
	float encumberance;
	float dura;
	float duraMax;
	float protBludgeoning, protSlashing, protPiercing, protAcid, protCold, protFire, protHoly, protLightning, protUnholy, protImpact;

};