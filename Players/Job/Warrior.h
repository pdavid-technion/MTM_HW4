#pragma once
#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>
#include <Utilities.h>

class Warrior : public Job {
public:
    Warrior(int maxHealthPoints = 150);
    int calculateCombatPower(int force, int level) const override;
    std::string combatMonster(Player& player, Monster& monster) const override;
    std::string printJobName() const override;
};