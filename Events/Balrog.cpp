#include "Balrog.h"
#include "../Players/PlayerConsts.h"

   Balrog::Balrog( int combatPower, 
            int loot,
            int damage): 
    SingleMonster(combatPower,loot,damage){}


    void Balrog::reactToCombat() {
        this->updateCombatPower(BALROG_COMBAT_REACTION);
    }

    string Balrog::getDescription() const{
        return "Balrog (power "+std::to_string(this->getCombatPower())+", loot " +
        std::to_string(this->getLoot()),", damage " + std::to_string(this->getDamage())+")";

    }

    int Balrog::getCombatPower() const{
        return SingleMonster::getCombatPower();
    }
    
    int Balrog::getLoot() const{
        return SingleMonster::getLoot();
    }
    
    int Balrog::getDamage() const {
        return SingleMonster::getDamage();
    }
    
    bool Balrog::isPack() const{
        return false;
    }
      
    void Balrog::addMonster(std::unique_ptr<Monster>){
            throw std::runtime_error("Operation not supported");
    }

    const std::vector<std::unique_ptr<Monster>>& Balrog::getMonsters() const{
            throw std::runtime_error("Opertaion not supported");
    }
