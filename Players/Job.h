#pragma once
#include <Player.h>
#include <../Events/Monster.h>

class Job {
public:

    virtual ~Job() = default;
    virtual int calculateCombatPower(int force, int level) const {
        return force + level;
    }
    virtual void combatMonster(Player& player, Monster& monster) const = 0;
};

class Warrior : public Job {
    public:
        int calculateCombatPower(int force, int level) const override;

        void combatMonster(Player& player, Monster& monster) const override;
};

class Archer : public Job {
    void combatMonster(Player& player, Monster& monster) const override;
};

class Magician : public Job {
    void combatMonster(Player& player, Monster& monster) const override;
};
