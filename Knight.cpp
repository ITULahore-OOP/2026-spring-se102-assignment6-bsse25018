#include "Knight.h"
//Inherits Warrior
Knight:: Knight():Warrior(){}
Knight:: Knight(string n,int h,int bP, int aR,int cB):Warrior(n,h,bP,aR),chargeBonus(cB){};
 int Knight:: getChargeBonus(){
    return  chargeBonus;
 };
 int Knight:: calculateBurstDamage(){
    int BasePower= getPower();
    int burstDamage=BasePower + chargeBonus;
    return burstDamage;
 };