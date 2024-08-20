#include "Player.h"
#include "JobFactory.h"
#include "Job.h"
#include "Character.h"
#include <string>
#include <PlayerConsts.h>
#include <iostream>

Player::Player(std::string name,
               int level,
               int force,
               int healthPoints,
               std::shared_ptr<JobFactory> jobFactory,
               std::shared_ptr<CharacterFactory> characterFactory)
    : name(name),
      level(level),
      force(force),
      healthPoints(healthPoints),
      job(jobFactory ? jobFactory->createJob() : nullptr),
      character(characterFactory ? characterFactory->createCharacter() : nullptr)
{
    healthPoints = job->getMaxHealthPoints();
}

Player::Player(std::string name,
               std::shared_ptr<JobFactory> jobFactory,
               std::shared_ptr<CharacterFactory> characterFactory) : 
               name(name),
               level(DEFAULT_LEVEL),
               force(DEFAULT_FORCE),
               healthPoints(DEFAULT_HEALTH_POINTS),
               job(jobFactory ? jobFactory->createJob() : nullptr),
               character(characterFactory ? characterFactory->createCharacter() : nullptr)
{
    healthPoints = job->getMaxHealthPoints();
}

Player::Player(const Player &other)
    : name(other.name),
      level(other.level),
      force(other.force),
      healthPoints(other.healthPoints),
      job(other.job ? other.job->clone() : nullptr),
      character(other.character ? other.character->clone() : nullptr) {}

Player::Player(Player &&other) noexcept
    : name(std::move(other.name)),
      level(other.level),
      force(other.force),
      healthPoints(other.healthPoints),
      job(other.job ? other.job->clone() : nullptr),
      character(other.character ? other.character->clone() : nullptr) {}

Player &Player::operator=(Player &&other) noexcept
{
    if (this != &other)
    {
        name = std::move(other.name);
        level = other.level;
        force = other.force;
        healthPoints = other.healthPoints;
        job = other.job ? other.job->clone() : nullptr;
        character = other.character ? other.character->clone() : nullptr;
    }
    return *this;
}

string Player::getDescription() const
{
    string description = name + ", " + job->printJobName() + " with " +
                        character->printCharacterName() + " character (level " +
                        std::to_string(level) + ", force " + std::to_string(force) + ")";
    return description;
}

string Player::getName() const{
    return name;
}

int Player::getLevel() const{
    return level;
}

int Player::getForce() const{
    return force;
}

int Player::getHealthPoints() const{
    return healthPoints;
}

int Player::getCoins() const{
    return this->job->getCoins();
}

int Player::getCombatPower() const{
    return this->job->calculateCombatPower(this->force, this->level);
}

void Player::winMonster(int loot){
    this->level += 1;
    this->job->setCoins(this->getCoins() + loot);
}

void Player::loseToMonster(int damage){
    this->healthPoints = std::max(0, this->healthPoints - damage);
}

void Player::closeEncounter(){
    this->healthPoints = std::max(0, this->healthPoints - CLOSE_ENCOUNTER_DAMAGE);
}

bool Player::applyDarknessConfusion(){
    if(this->force  == 0){
        return false;
    }
    this->force = std::max(0, this->force - SOLAR_ECLIPSE_EXPOSURE);
    return true;
}

void Player::applyDarknessMagic(){
    this->force = this->force + SOLAR_ECLIPSE_EXPOSURE;
}

int Player::getMaxHealthPoints(){
    return this->job->getMaxHealthPoints();
}

bool Player::buyPotions(int potionAmount){
    if( this->getCoins() >= potionAmount * POTION_COST){
        this->healthPoints = std::min(this->getMaxHealthPoints(),
                                  this->getHealthPoints() + (potionAmount * POTION_HEALTHPOINTS));
        this->job->setCoins(this->getCoins() - potionAmount * POTION_COST);
        return true;
    }
    return false;
    
}

string Player::combatMonster(Monster &monster){
    return this->job->combatMonster(*this, monster);
}

string Player::reactToSolarEclipse(){
    return this->job->reactToSolarEclipse(*this);
}

string Player::reactToPotionsMerchant(){
    return this->character->reactToPotionsMerchant(*this);
}

bool Player::isStillPlaying() const{
    return this->getHealthPoints() > 0;
}

bool Player::operator>(Player const &other) const{
    if (level != other.level){
        return level > other.level;
    }
    if (getCoins() != other.getCoins()){
        return getCoins() > other.getCoins();
    }
    return name < other.name;
}
