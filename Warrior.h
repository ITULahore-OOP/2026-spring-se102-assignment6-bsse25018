#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;
class Warrior:public Hero{
int armorRating;
public:
Warrior();
Warrior(string n,int h, int bP,int aR);
~Warrior();
int getArmor();
int calculateEffectiveHealth();
};



#endif