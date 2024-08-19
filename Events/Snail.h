#pragma once
#include "SingleMonster.h"
#include "../Players/PlayerConsts.h"

class Snail: public SingleMonster {
    public:
    Snail(  int combatPower = SNAIL_COMBAT_POWER,
            int loot = SNAIL_LOOT,
            int damage = SNAIL_DAMAGE);
    ~Snail() = default;

    string getDescription() const override;

    int getCombatPower() const override;
    
    int getLoot() const override;
    
    int getDamage() const override;
    
    bool isPack() const override;

    void reactToCombat() override;
      
    void addMonster(std::unique_ptr<Monster>) override;

    const std::vector<std::unique_ptr<Monster>>& getMonsters() const override;
};