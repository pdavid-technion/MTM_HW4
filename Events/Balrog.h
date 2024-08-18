#pragma once
#include <SingleMonster.h>

class Balrog: public SingleMonster {
    Balrog(int combatPower = 15, int loot = 100, int damage = 9001): 
    SingleMonster(combatPower,loot,damage){}

    virtual void reactToCombat() override{
        this->updateCombatPower(2);
    }
};