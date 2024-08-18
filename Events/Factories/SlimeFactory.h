#pragma once

#include "SingleMonsterFactory.h"
#include "../Slime.h"

class SlimeFactory : public SingleMonsterFactory {
public:
    SlimeFactory() = default;
    std::unique_ptr<Monster> createMonster() const override {
        return std::make_unique<Slime>(); // TODO - SHELLY - Add consts
    }
};