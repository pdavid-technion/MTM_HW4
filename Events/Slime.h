#pragma once
#include <SingleMonster.h>

class Slime: public SingleMonster {
    Slime(int combatPower = 12, int loot = 5, int damage = 25): SingleMonster(combatPower,loot,damage){}
};