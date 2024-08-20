#pragma once
#include "./Player.h"
#include "../Events/Event.h"
#include "PlayerConsts.h"

class Job {
public:

    Job(int maxHealthPoints = DEFAULT_HEALTH_POINTS, int coins = DEFAULT_COINS );
    virtual ~Job() = default;
    virtual int calculateCombatPower(int force, int level) const = 0;
    virtual string combatMonster(Player& player, Monster& monster) const = 0;
    virtual string reactToSolarEclipse( Player& player) const = 0;
    int getMaxHealthPoints();
    int getCoins();
    void setCoins(int newCoins);
    virtual string printJobName() const = 0;
    virtual std::unique_ptr<Job> clone() const = 0;

    private:
        int maxHealthPoints;
        int coins;
};