#pragma once

#include "SingleMonsterFactory.h"
#include "SingleMonster.h"

class BalrogFactory : public SingleMonsterFactory {
public:
    BalrogFactory() = default;
    std::shared_ptr<Monster> createMonster() const override {
        return std::make_shared<SingleMonster>(15, 100, 9001); // TODO - SHELLY - Add consts
    }
};