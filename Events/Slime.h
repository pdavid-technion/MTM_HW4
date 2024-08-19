#pragma once
#include "SingleMonster.h"
#include <string>
#include "GameConsts.h"

class Slime: public SingleMonster {
    
    public:
    Slime(  int combatPower = SLIME_COMBAT_POWER,
            int loot = SLIME_LOOT,
            int damage = SLIME_DAMAGE): SingleMonster(combatPower,loot,damage){}
    ~Slime() = default;
    string getDescription() const override{
        return "Slime (power "+std::to_string(this->getCombatPower())+", loot " +
        std::to_string(this->getLoot()),", damage " + std::to_string(this->getDamage())+")";

    }

    int getCombatPower() const override{
        return this->getCombatPower();
    }
    
    int getLoot() const override{
        return this->getLoot();
    }
    
    int getDamage() const override{
        return this->getDamage();
    }
    
    bool isPack() const override{
        return false;
    }

    void reactToCombat() override{}
      
    void addMonster(std::unique_ptr<Monster>) override{
            throw std::runtime_error("Operation not supported");
    }

    const std::vector<std::unique_ptr<Monster>>& getMonsters() const override{
            throw std::runtime_error("Opertaion not supported");
    }
};