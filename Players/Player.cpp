#include <Player.h>
#include <JobFactory.h>


Player::Player( std::string name,
                int level = 1,
                int force = 10,
                int healthPoints = 100,
                int coins = 10,
                std::unique_ptr<JobFactory> jobFactory,
                std::unique_ptr<CharacterFactory> characterFactory):
                name(name),
                level(level),
                force(force),
                healthPoints(healthPoints),
                coins(coins),
                job(jobFactory->createJob()),
                character(characterFactory->createCharacter()) {}

string Player::getDescription() const{
    return "DAVID IMPLEMENT PLS";
}

string Player::getName() const{
    return "DAVID IMPLEMENT PLS";
}

int Player::getLevel() const{
    return this->level;
}

int Player::getForce() const{
    return this->force;
}

int Player::getHealthPoints() const{
   return this->healthPoints;
}

int Player::getCoins() const{
    return this->coins;
}