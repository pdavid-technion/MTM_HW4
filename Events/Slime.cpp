#include "Slime.h"
#include <string>
#include "../Players/PlayerConsts.h"

    Slime::Slime( int combatPower,
                int loot,
                int damage): SingleMonster(combatPower,loot,damage){}
  
    string Slime::getDescription() const {
        return "Slime (power "+std::to_string(this->getCombatPower())+", loot " +
        std::to_string(this->getLoot()),", damage " + std::to_string(this->getDamage())+")";

    }

    int Slime::getCombatPower() const {
        return SingleMonster::getCombatPower();
    }
    
    int Slime::getLoot() const{
        return SingleMonster::getLoot();
    }
    
    int Slime::getDamage() const{
        return SingleMonster::getDamage();
    }
    
    bool Slime::isPack() const{
        return false;
    }

    void Slime::reactToCombat() {}
      
    void Slime::addMonster(std::unique_ptr<Monster>){
            throw std::runtime_error("Operation not supported");
    }

    const std::vector<std::unique_ptr<Monster>>& Slime::getMonsters() const{
            throw std::runtime_error("Opertaion not supported");
    }