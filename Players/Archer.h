#pragma once
#include "Job.h"
#include "Player.h"
#include "../Events/Monster.h"
#include "../Utilities.h"

class Archer : public Job {
public:
    Archer(int coins = ARCHER_COINS);
    ~Archer() = default;
    string printJobName() const override;
    string reactToSolarEclipse( Player& player) const override;
    int calculateCombatPower(int force, int level) const override;
    std::string combatMonster(Player& player, Monster& monster) const override;
    std::unique_ptr<Job> clone() const override;
};