#pragma once
#include <SingleMonster.h>

class Snail: public SingleMonster {
    Snail(int combatPower = 5, int loot = 2, int damage = 10): SingleMonster(combatPower,loot,damage){}
};