#ifndef HERO_H
#define HERO_H
#include<iostream>
#include <string>
using namespace std;
class Hero{  
string heroName;
int health;
int basePower;
public:
Hero();
Hero(string n,int h,int bP);
virtual ~Hero();
string getName()const;
int getHealth()const;
int getPower()const;

void takeDamage(int damage);
bool operator > (const Hero& h);
int operator +(const Hero& h);

};



#endif