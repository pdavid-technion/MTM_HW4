
// #pragma once

// #include <string>
// #include "Factories/JobFactory.h"
// #include "Factories/CharacterFactory.h"
// #include "../Events/Monster.h"

// using std::string;

// class Player {

// private:
//     string name;
//     int level;
//     int force;
//     int healthPoints;
//     std::unique_ptr<Job> job;
//     std::unique_ptr<Character> character;

// public:
//     Player(std::string name,
//             int level = 1,
//             int force = 10,
//             int healthPoints = 100,
//             std::unique_ptr<JobFactory> jobFactory = nullptr,
//             std::unique_ptr<CharacterFactory> characterFactory = nullptr);
//     /**
//      * Gets the description of the player
//      *
//      * @return - description of the player
//      */
//     string getDescription() const;

//     /**
//      * Gets the name of the player
//      *
//      * @return - name of the player
//      */
//     string getName() const;

//     /**
//      * Gets the current level of the player
//      *
//      * @return - level of the player
//      */
//     int getLevel() const;

//     /**
//      * Gets the of force the player has
//      *
//      * @return - force points of the player
//      */
//     int getForce() const;

//     /**
//      * Gets the amount of health points the player currently has
//      *
//      * @return - health points of the player
//      */
//     int getHealthPoints() const;

//     /**
//      * Gets the amount of coins the player has
//      *
//      * @return - coins of the player
//      */
//     int getCoins() const;

//     int getCombatPower() const;

//     void winMonster( int loot );

//     void loseToMonster( int damage );

//     void closeEncounter();

//     void applyDarknessConfusion();

//     void applyDarknessMagic();

//     int getMaxHealthPoints();

//     void buyPotions(int potionAmount);

//     string combatMonster( Monster& monster);

//     string reactToSolarEclipse();

//     string reactToPotionsMerchant();

//     bool isStillPlaying() const;

//     //bool operator<(const Player& other) const;
//     bool operator<(Player const&) const; 
// };

#pragma once

#include <string>
#include "Factories/JobFactory.h"
#include "Factories/CharacterFactory.h"
#include "../Events/Monster.h"

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
            std::unique_ptr<JobFactory> jobFactory = nullptr,
            std::unique_ptr<CharacterFactory> characterFactory = nullptr);
    
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
    void applyDarknessConfusion();
    void applyDarknessMagic();
    int getMaxHealthPoints();
    void buyPotions(int potionAmount);
    string combatMonster(Monster& monster);
    string reactToSolarEclipse();
    string reactToPotionsMerchant();
    bool isStillPlaying() const;
    bool operator<(Player const&) const;
};
