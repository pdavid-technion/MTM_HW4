#pragma once
#include "SingleMonster.h"
#include <string>
#include "../Players/PlayerConsts.h"

class Slime: public SingleMonster {
    
    public:
    Slime(  int combatPower = SLIME_COMBAT_POWER,
            int loot = SLIME_LOOT,
            int damage = SLIME_DAMAGE);
    ~Slime() = default;
    string getDescription() const override;

    int getCombatPower() const override;
    
    int getLoot() const override;
    
    int getDamage() const override;
    
    bool isPack() const override;

    void reactToCombat() override;
      
    void addMonster(std::unique_ptr<Monster>) override;

    const std::vector<std::unique_ptr<Monster>>& getMonsters() const override;
};