#pragma once

#include "SingleMonsterFactory.h"
#include "../Snail.h"

class SnailFactory : public SingleMonsterFactory {
public:
    SnailFactory() = default;
    std::unique_ptr<Monster> createMonster() const override {
        return std::make_unique<Snail>(); // TODO - SHELLY - Add consts
    }
};