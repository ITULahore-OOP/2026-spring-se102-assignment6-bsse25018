#include "MagicalEntity.h"
MagicalEntity:: MagicalEntity(int mP,int sP):manaPool(mP),spellPower(sP){};
int MagicalEntity:: getMana()const{
  return manaPool;
}
int MagicalEntity:: getSpellPower()const{
  return spellPower;
};