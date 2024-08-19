#pragma once
#include "Monster.h"

class SingleMonster: public Monster {
    public:
        
        virtual ~SingleMonster() = default;
        SingleMonster(int combatPower, int loot, int damage);

        int getCombatPower() const override;

        int getLoot() const override;

        int getDamage() const override;

        bool isPack() const override;

        void updateCombatPower(int extraPower);

        protected:
            int combatPower;
            int loot;
            int damage;
};