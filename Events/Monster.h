#pragma once
#include <vector>
#include <memory>


class Monster{
    public:
        virtual ~Monster() = default;

        virtual int getCombatPower() const = 0;
        virtual int getLoot() const = 0;
        virtual int getDamage() const = 0;
        virtual bool isPack() const = 0;

        virtual void addMonster(std::shared_ptr<Monster>) {
            throw std::runtime_error("Operation not supported");
        }

        virtual const std::vector<std::shared_ptr<Monster>>& getMonsters() const {
            throw std::runtime_error("Opertaion not supported");
        }
};