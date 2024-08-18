#pragma once
 
#include <Monster.h>
#include <memory>
#include <vector>

class MonsterPack: public Monster{
    public:
        void addMonster(std::shared_ptr<Monster> monster ) override{
            monsters.push_back(monster);
        }

        int getCombatPower() const override {
            int totalCombatPower = 0;
            
            for( const auto& monster: monsters){
                totalCombatPower += monster->getCombatPower();
            }
            return totalCombatPower;
        }

        int getLoot() const override {
            int totalLoot = 0;

            for(const auto& monster : monsters ){
                totalLoot += monster->getLoot();
            }

            return totalLoot;
        }

        int getDamage() const override{
            int totalDamage = 0;

            for( const auto& monster: monsters ){
                totalDamage += monster->getDamage();
            }

            return totalDamage;
        }

        bool isPack() const override{
            return true;
        }

        const std::vector<std::shared_ptr<Monster>>& getMonsters() const override {
            return monsters;
        }

        virtual void reactToCombat() override{
        for( const auto& monster: monsters ){
                monster->reactToCombat();
            }
        
        }

    private:
        std::vector<std::shared_ptr<Monster>> monsters;
};