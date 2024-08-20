#pragma once
 
#include <string>
#include "Monster.h"
#include <memory>
#include <vector>

class MonsterPack: public Monster{
    public:
        ~MonsterPack() = default;
        void addMonster(std::unique_ptr<Monster> monster ) override{
            monsters.push_back(std::move(monster));
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

        const std::vector<std::unique_ptr<Monster>>& getMonsters() const override {
            return monsters;
        }

        void reactToCombat() override{
        for( const auto& monster: monsters ){
                monster->reactToCombat();
            }
        
        }

        virtual string getDescription() const override{
            return "Pack of " + std::to_string(monsters.size())+ " members (power " +
            std::to_string(this->getCombatPower())+", loot " +
            std::to_string(this->getLoot())+", damage " + std::to_string(this->getDamage())+")";
        }

    private:
        std::vector<std::unique_ptr<Monster>> monsters;
};