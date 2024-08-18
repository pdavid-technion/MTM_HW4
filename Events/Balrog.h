#pragma once
#include <SingleMonster.h>

class Balrog: public SingleMonster {
    Balrog(int combatPower = 15, int loot = 100, int damage = 9001): 
    SingleMonster(combatPower,loot,damage){}

    virtual void reactToCombat() override{
        this->updateCombatPower(2);
    }

    string getDescription() const override{
        return "Balrog (power "+std::to_string(this->getCombatPower())+", loot " +
        std::to_string(this->getLoot()),", damage " + std::to_string(this->getDamage())+")";

    }
};