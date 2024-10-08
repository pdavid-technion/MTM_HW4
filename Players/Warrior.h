#pragma once
#include "Job.h"
#include "Player.h"
#include "../Events/Monster.h"
#include "../Utilities.h"

class Warrior : public Job {
public:
    Warrior(int maxHealthPoints = WARRIOR_MAX_HEALTHPOINTS);
    ~Warrior() = default;
    int calculateCombatPower(int force, int level) const override;
    std::string combatMonster(Player& player, Monster& monster) const override;
    std::string printJobName() const override;
    string reactToSolarEclipse( Player& player) const override;
    std::unique_ptr<Job> clone() const override;
};