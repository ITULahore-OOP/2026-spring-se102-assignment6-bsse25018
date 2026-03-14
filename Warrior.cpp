#include "Warrior.h"
// Inherits Hero
Warrior:: Warrior(){
    armorRating = 100;

}
Warrior:: Warrior(string n,int h, int bP,int aR):Hero(n,h,bP),armorRating(aR){};
Warrior:: ~Warrior(){};
int Warrior:: getArmor(){
    return armorRating;
};
int Warrior::calculateEffectiveHealth(){
    int health= getHealth();
    int effectiveHealth = health + (armorRating*2);
    return effectiveHealth;
};