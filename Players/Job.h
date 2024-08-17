#pragma once
#include <Player.h>
#include <../Events/Monster.h>

class Job {
public:

    Job(int maxHealthPoints = 100, int coins = 10 ); //TODO - SHELLY - consts
    virtual ~Job() = default;
    virtual int calculateCombatPower(int force, int level) const {};
    virtual void combatMonster(Player& player, Monster& monster) const = 0;
    virtual void reactToSolarEclipse( Player& player) const {};
    int getMaxHealthPoints();
    int getCoins();
    void setCoins(int newCoins);

    private:
        int maxHealthPoints;
        int coins;
};

class Warrior : public Job {
    public:
        Warrior(int maxHealthPoints = 150);
        int calculateCombatPower(int force, int level) const override;
        void combatMonster(Player& player, Monster& monster) const override;
};

class Archer : public Job {
    Archer(int coins = 20);
};

class Magician : public Job {
    void reactToSolarEclipse( Player& player) const override;
};
