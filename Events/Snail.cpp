#include "Snail.h"
#include "../Players/PlayerConsts.h"
#include <iostream>

    Snail::Snail(
            int combatPower,
            int loot,
            int damage):
            SingleMonster(combatPower,loot,damage){ }


    string Snail::getDescription() const {
        string result = "Snail (power "+std::to_string(this->getCombatPower())+", loot " +
        std::to_string(this->getLoot())+", damage " + std::to_string(this->getDamage())+")";
        return result;
    }

    int Snail::getCombatPower() const {
        return SingleMonster::getCombatPower();
    }
    
    int Snail::getLoot() const {
        return SingleMonster::getLoot();
    }
    
    int Snail::getDamage() const {
        return SingleMonster::getDamage();
    }
    
    bool Snail::isPack() const {
        return false;
    }

    void Snail::reactToCombat() {}
      
    void Snail::addMonster(std::unique_ptr<Monster>) {
            throw std::runtime_error("Operation not supported");
    }

    const std::vector<std::unique_ptr<Monster>>& Snail::getMonsters() const{
            throw std::runtime_error("Opertaion not supported");
    }