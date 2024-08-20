#pragma once

#include <string>
#include "JobFactory.h"
#include "CharacterFactory.h"
#include "../Events/Monster.h"
#include "PlayerConsts.h"

using std::string;

class Player {
private:
    string name;
    int level;
    int force;
    int healthPoints;
    std::unique_ptr<Job> job;
    std::unique_ptr<Character> character;

public:
    Player(std::string name,
            int level = DEFAULT_LEVEL,
            int force = DEFAULT_FORCE,
            int healthPoints = DEFAULT_HEALTH_POINTS,
            std::shared_ptr<JobFactory> jobFactory = nullptr,
            std::shared_ptr<CharacterFactory> characterFactory = nullptr);

            Player(std::string name,
            std::shared_ptr<JobFactory> jobFactory = nullptr,
            std::shared_ptr<CharacterFactory> characterFactory = nullptr);

    Player(Player&& other) noexcept;
    Player(const Player& other);

    Player& operator=(Player&& other) noexcept;
    
    ~Player() = default;

    string getDescription() const;
    string getName() const;
    int getLevel() const;
    int getForce() const;
    int getHealthPoints() const;
    int getCoins() const;
    int getCombatPower() const;
    void winMonster(int loot);
    void loseToMonster(int damage);
    void closeEncounter();
    bool applyDarknessConfusion();
    void applyDarknessMagic();
    int getMaxHealthPoints();
    bool buyPotions(int potionAmount);
    string combatMonster(Monster& monster);
    string reactToSolarEclipse();
    string reactToPotionsMerchant();
    bool isStillPlaying() const;
    bool operator>(Player const&) const;
};