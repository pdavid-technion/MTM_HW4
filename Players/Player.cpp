#include <Player.h>
#include <JobFactory.h>
#include <Job.h>


Player::Player( std::string name,
                int level = 1,
                int force = 10,
                int healthPoints = 100,
                int maxHealthPoints = 100,
                int coins = 10,
                std::unique_ptr<JobFactory> jobFactory,
                std::unique_ptr<CharacterFactory> characterFactory):
                name(name),
                level(level),
                force(force),
                healthPoints(healthPoints),
                maxHealthPoints(maxHealthPoints),
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

int Player::getCombatPower() const{
    return this->job->calculateCombatPower(this->force, this->level);
}

void Player::winMonster( int loot ) {
        this->level += 1;
        this->coins += loot;
}

void Player::loseToMonster( int damage ){
    this->healthPoints = std::max(0, this->healthPoints - damage);
}

void Player::closeEncounter(){
    this->healthPoints = std::max(0, this->healthPoints - 10 ); //TODO - SHELLY - consts
}

void Player::applyDarknessConfusion(){
    this->healthPoints = std::max(0, this->healthPoints-1);
}

void Player::applyDarknessMagic(){
    this->healthPoints = std::min(this->maxHealthPoints, this->healthPoints+1);
}