
#pragma once

#include <string>
#include <JobFactory.h>
#include <CharacterFactory.h>
#include <../Events/Monster.h>

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
            int level = 1,
            int force = 10,
            int healthPoints = 100,
            std::unique_ptr<JobFactory> jobFactory,
            std::unique_ptr<CharacterFactory> characterFactory);
    /**
     * Gets the description of the player
     *
     * @return - description of the player
     */
    string getDescription() const; //DAVID

    /**
     * Gets the name of the player
     *
     * @return - name of the player
     */
    string getName() const; //DAVID

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
     */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
     */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
     */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
     */
    int getCoins() const;

    int getCombatPower() const;

    void winMonster( int loot );

    void loseToMonster( int damage );

    void closeEncounter();

    void applyDarknessConfusion();

    void applyDarknessMagic();

    int getMaxHealthPoints();

    void buyPotions(int potionAmount);

    string combatMonster( Monster& monster);

    string reactToSolarEclipse();

    string reactToPotionsMerchant();

    bool operator<(const Player& other) const;
};
