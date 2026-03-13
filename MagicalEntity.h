#ifndef MAGICALENTITY_H
#define MAGICALENTITY_H
#include <iostream>
#include <string>
using namespace std;
class MagicalEntity{
int manaPool;
int spellPower;
public:
MagicalEntity(int mP,int sP);
int getMana()const;
int getSpellPower()const;
};




#endif