#pragma once
#include <vector>
#include <memory>
#include <stdexcept>
#include <string>

using std::string;

class Monster{
    public:
        virtual ~Monster() = default;

        virtual int getCombatPower() const = 0;
        virtual int getLoot() const = 0;
        virtual int getDamage() const = 0;
        virtual bool isPack() const = 0;
        virtual void reactToCombat() = 0;
        virtual string getDescription() const = 0;

        virtual void addMonster(std::unique_ptr<Monster>)  = 0;

        virtual const std::vector<std::unique_ptr<Monster>>& getMonsters() const = 0;
};