#ifndef SPELLBLADE_H
#define SPELLBLADE_H
#include <iostream>
#include <string>
#include "Warrior.h"
#include "MagicalEntity.h"
using namespace std;
class SpellBlade:public Warrior, public MagicalEntity{
public:
SpellBlade();
SpellBlade(string n, int h,int bP,int aR,int mP,int sP);
int calculateHybridDamage();
};



#endif