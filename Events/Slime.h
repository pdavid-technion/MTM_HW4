#pragma once
#include <SingleMonster.h>
#include <string>

class Slime: public SingleMonster {
    Slime(int combatPower = 12, int loot = 5, int damage = 25): SingleMonster(combatPower,loot,damage){}
    string getDescription() const override{
        return "Slime (power "+std::to_string(this->getCombatPower())+", loot " +
        std::to_string(this->getLoot()),", damage " + std::to_string(this->getDamage())+")";

    }
};