#pragma once

#include "SingleMonsterFactory.h"
#include "SingleMonster.h"

class SlimeFactory : public SingleMonsterFactory {
public:
    std::shared_ptr<Monster> createMonster() const override {
        return std::make_shared<SingleMonster>(12, 5, 25); // TODO - SHELLY - Add consts
    }
};