#pragma once

#include "SingleMonsterFactory.h"
#include "Slime.h"

class SlimeFactory : public SingleMonsterFactory {
public:
    SlimeFactory() = default;
    std::shared_ptr<Monster> createMonster() const override {
        return std::make_shared<Slime>(); // TODO - SHELLY - Add consts
    }
};