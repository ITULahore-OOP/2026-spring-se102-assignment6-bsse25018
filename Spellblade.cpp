#include "SpellBlade.h"
SpellBlade:: SpellBlade() : Warrior(), MagicalEntity(0, 0) {}
SpellBlade:: SpellBlade(string n, int h,int bP,int aR,int mP,int sP):Warrior(n,h,bP,aR),MagicalEntity(mP,sP){};
int SpellBlade:: calculateHybridDamage(){
    int base=getPower();
    int spell=getSpellPower();
    int total = base+spell;
    return total;
};