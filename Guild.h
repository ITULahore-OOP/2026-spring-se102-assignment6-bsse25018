#ifndef GUILD_H
#define GUILD_H
#include <iostream>
#include <string>
#include "Hero.h"
using namespace std;
class Guild{
string guildName;
Hero* roster[15];
int memberCount;
public:
Guild(string name);
~Guild();
string getName();
int calculateTotalGuildPower();
void displayGuildStats();
void operator+=(Hero* h);
friend ostream& operator <<(ostream& , Guild &g);

Hero* getHero(int index);
int getMemberCount();
}; 



#endif