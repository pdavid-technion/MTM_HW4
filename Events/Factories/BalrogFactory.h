#pragma once

#include "SingleMonsterFactory.h"
#include "Balrog.h"

class BalrogFactory : public SingleMonsterFactory {
public:
    BalrogFactory() = default;
    std::shared_ptr<Monster> createMonster() const override {
        return std::make_shared<Balrog>(); // TODO - SHELLY - Add consts
    }
};