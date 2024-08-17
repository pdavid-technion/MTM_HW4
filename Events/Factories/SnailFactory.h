#pragma once

#include "SingleMonsterFactory.h"
#include "SingleMonster.h"

class SnailFactory : public SingleMonsterFactory {
public:
    std::shared_ptr<Monster> createMonster() const override {
        return std::make_shared<SingleMonster>(5, 2, 10); // TODO - SHELLY - Add consts
    }
};