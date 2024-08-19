#pragma once
#include "SingleMonster.h"
#include "../Players/PlayerConsts.h"

class Balrog: public SingleMonster {
    public:
    Balrog( int combatPower = BALROG_COMBAT_POWER, 
            int loot = BALROG_LOOT,
            int damage = BALROG_DAMAGE); 
     ~Balrog() = default;

    virtual void reactToCombat() override;

    string getDescription() const override;

    int getCombatPower() const override;
    
    int getLoot() const override;
    
    int getDamage() const override;
    
    bool isPack() const override;
      
    void addMonster(std::unique_ptr<Monster>) override;

    const std::vector<std::unique_ptr<Monster>>& getMonsters() const override;
};