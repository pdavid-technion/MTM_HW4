#pragma once
#include "SingleMonster.h"
#include "GameConsts.h"

class Balrog: public SingleMonster {
    public:
    Balrog( int combatPower = BALROG_COMBAT_POWER, 
            int loot = BALROG_LOOT,
            int damage = BALROG_DAMAGE): 
    SingleMonster(combatPower,loot,damage){}
     ~Balrog() = default;

    virtual void reactToCombat() override{
        this->updateCombatPower(BALROG_COMBAT_REACTION);
    }

    string getDescription() const override{
        return "Balrog (power "+std::to_string(this->getCombatPower())+", loot " +
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
      
    void addMonster(std::unique_ptr<Monster>) override{
            throw std::runtime_error("Operation not supported");
    }

    const std::vector<std::unique_ptr<Monster>>& getMonsters() const override{
            throw std::runtime_error("Opertaion not supported");
    }
};