#pragma once

#include "SingleMonster.h"
#include "MonsterFactory.h"

class SingleMonsterFactory: public MonsterFactory{
    public:
    SingleMonsterFactory() = default;
    virtual ~SingleMonsterFactory() = default;
};