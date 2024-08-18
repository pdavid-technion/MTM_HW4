#pragma once

#include <memory>
#include <vector>

class Monster;

class MonsterFactory {
    public:
        MonsterFactory() = default;
        virtual ~MonsterFactory() = default;
        virtual std::shared_ptr<Monster> createMonster() const = 0;
};