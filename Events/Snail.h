#pragma once
#include <SingleMonster.h>

class Snail: public SingleMonster {
    Snail(int combatPower = 5, int loot = 2, int damage = 10): SingleMonster(combatPower,loot,damage){}
    string getDescription() const override{
        return "Snail (power "+std::to_string(this->getCombatPower())+", loot " +
        std::to_string(this->getLoot()),", damage " + std::to_string(this->getDamage())+")";

    }
};