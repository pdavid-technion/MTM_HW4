#pragma once
#include <Monster.h>

class SingleMonster: public Monster {
    public:
        
        SingleMonster(int combatPower, int loot, int damage):
            combatPower(combatPower),loot(loot), damage(damage){}

        int getCombatPower() const override {
            return combatPower;
        }

        int getLoot() const override{
            return loot;
        }

        int getDamage() const override{
            return damage;
        }

        bool isPack() const override{
            return false;
        }

        private:
            int combatPower;
            int loot;
            int damage;
};