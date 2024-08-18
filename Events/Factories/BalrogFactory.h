#pragma once

#include "SingleMonsterFactory.h"
#include "../Balrog.h"

class BalrogFactory : public SingleMonsterFactory {
public:
    BalrogFactory() = default;
    std::unique_ptr<Monster> createMonster() const override {
        return std::make_unique<Balrog>(); // TODO - SHELLY - Add consts
    }
};