#pragma once

#include "SingleMonster.h"
#include "MonsterFactory.h"

class SingleMonsterFactory: public MonsterFactory{
    virtual ~SingleMonsterFactory() = default;
};