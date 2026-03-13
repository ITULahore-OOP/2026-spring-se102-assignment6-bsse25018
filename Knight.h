#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <string>
#include "Warrior.h"
using namespace std;
class Knight :public Warrior{
 int chargeBonus;
 public:
 Knight();
 Knight(string n,int h,int bP, int aR,int cB);
 int getChargeBonus();
 int calculateBurstDamage();
};



#endif