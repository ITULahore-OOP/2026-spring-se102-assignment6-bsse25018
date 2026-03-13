#include "Hero.h"
Hero:: Hero(){
    heroName="Ragnar Lothbrok";
    health = 100;
    basePower=100;
}
Hero:: Hero(string n,int h,int bP):heroName(n),health(h),basePower(bP){};
 Hero:: ~Hero(){};
string Hero:: getName()const{
    return heroName;
};
int Hero:: getHealth()const{
    return health;
};
int Hero:: getPower()const{
    return basePower;
};

void Hero:: takeDamage(int damage){
    health -= damage;
        if (health < 0)
            health = 0;
};
bool Hero:: operator > (const Hero& h){
 return (basePower > h.basePower);
};
int Hero:: operator +(const Hero& h){
  int temp; 
  temp = health + h.health;
  return temp;
};