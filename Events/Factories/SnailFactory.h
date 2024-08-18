#pragma once

#include "SingleMonsterFactory.h"
#include "Snail.h"

class SnailFactory : public SingleMonsterFactory {
public:
    SnailFactory() = default;
    std::shared_ptr<Monster> createMonster() const override {
        return std::make_shared<Snail>(); // TODO - SHELLY - Add consts
    }
};