#pragma once
#include "SingleMonster.h"
#include "GameConsts.h"

class Snail: public SingleMonster {
    public:
    Snail(  int combatPower = SNAIL_COMBAT_POWER,
            int loot = SNAIL_LOOT,
            int damage = SNAIL_DAMAGE): SingleMonster(combatPower,loot,damage){}
    ~Snail() = default;

    string getDescription() const override{
        return "Snail (power "+std::to_string(this->getCombatPower())+", loot " +
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