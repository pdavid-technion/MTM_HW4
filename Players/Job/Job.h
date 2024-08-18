#pragma once
#include "../Player.h"
#include "../../Events/Event.h"

class Job {
public:

    Job(int maxHealthPoints = 100, int coins = 10 ); //TODO - SHELLY - consts
    virtual ~Job() = default;
    virtual int calculateCombatPower(int force, int level) const = 0;
    virtual string combatMonster(Player& player, Monster& monster) const = 0;
    virtual string reactToSolarEclipse( Player& player) const = 0;
    int getMaxHealthPoints();
    int getCoins();
    void setCoins(int newCoins);
    virtual string printJobName() const = 0;

    private:
        int maxHealthPoints;
        int coins;
};