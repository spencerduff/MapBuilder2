#include "Enchants.h"

float Enchant::setQuality(float mq1, float mq2, float mq3){
	return (mq1 + mq2 + mq3) / 3.0;
}

Keen::Keen(){
	enchantType = keen;
	itemType = weapons;
	requirement1 = bile;
	requirement2 = cinder;
	requirement3 = darktaint;
	requiredCatalyst = numen;
	name = "Keen";
	quality = 1.0;
	dmgModifier = .024;
}

void Keen::enchant(EnchantingMat* m1, EnchantingMat* m2, EnchantingMat* m3, EnchantingCatalyst* c, Item* i){
	quality = setQuality(m1->getQuality(), m2->getQuality(), m3->getQuality());
	dmgModifier = (quality * .024);
	i->enchant(this); //Figure out what type of item you're enchanting
}

void Keen::enchant(Weapon* w){
	w->keen(this);
}