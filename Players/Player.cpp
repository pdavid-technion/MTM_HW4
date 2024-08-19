#include "Player.h"
#include "JobFactory.h"
#include "Job.h"
#include "Character.h"
#include <string>
#include <GameConsts.h>

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
                  character(characterFactory ? characterFactory->createCharacter() : nullptr) {}

Player::Player(const Player& other)
    : name(other.name),
      level(other.level),
      force(other.force),
      healthPoints(other.healthPoints),
      job(other.job ? other.job->clone() : nullptr),        
      character(other.character ? other.character->clone() : nullptr)  {}

Player::Player(Player&& other) noexcept
    : name(std::move(other.name)),
      level(other.level),
      force(other.force),
      healthPoints(other.healthPoints),
      job(other.job ? other.job->clone() : nullptr),
      character(other.character ? other.character->clone() : nullptr) {}

Player& Player::operator=(Player&& other) noexcept {
    if (this != &other) {


        // Transfer the non-pointer data members
        name = std::move(other.name);
        level = other.level;
        force = other.force;
        healthPoints = other.healthPoints;

        // Deep copy the job and character from the other player
        job = other.job ? other.job->clone() : nullptr;
        character = other.character ? other.character->clone() : nullptr;
    }
    return *this;
}

string Player::getDescription() const {
    string str = name + ", " + job->printJobName() + " with " + character->printCharacterName() +
    " (" + std::to_string(level) + ", " + std::to_string(force) + ")";
    return str;
}

string Player::getName() const {
    return name;
}

int Player::getLevel() const {
    return level;
}

int Player::getForce() const {
    return force;
}

int Player::getHealthPoints() const {
    return healthPoints;
}

int Player::getCoins() const {
    return this->job->getCoins();
}

int Player::getCombatPower() const {
    return this->job->calculateCombatPower(this->force, this->level);
}

void Player::winMonster(int loot) {
    this->level += 1;
    this->job->setCoins(this->getCoins() + loot);
}

void Player::loseToMonster(int damage) {
    this->healthPoints = std::max(0, this->healthPoints - damage);
}

void Player::closeEncounter() {
    this->healthPoints = std::max(0, this->healthPoints - CLOSE_ENCOUNTER_DAMAGE);
}

void Player::applyDarknessConfusion() {
    this->healthPoints = std::max(0, this->healthPoints - SOLAR_ECLIPSE_EXPOSURE);
}

void Player::applyDarknessMagic() {
    this->healthPoints = std::min(this->getMaxHealthPoints(), this->healthPoints + SOLAR_ECLIPSE_EXPOSURE);
}

int Player::getMaxHealthPoints() {
    return this->job->getMaxHealthPoints();
}

void Player::buyPotions(int potionAmount) {
    this->healthPoints = std::min(this->getMaxHealthPoints(), 
        this->getHealthPoints() + (potionAmount * POTION_HEALTHPOINTS));
    this->job->setCoins(this->getCoins() - potionAmount * POTION_COST);
}

string Player::combatMonster(Monster& monster) {
    return this->job->combatMonster(*this, monster);
}

string Player::reactToSolarEclipse() {
    return this->job->reactToSolarEclipse(*this);
}

string Player::reactToPotionsMerchant() {
    return this->character->reactToPotionsMerchant(*this);
}

bool Player::isStillPlaying() const {
    return this->getHealthPoints() > 0;
}

bool Player::operator<(Player const& other) const {
    if (level != other.level) {
        return level > other.level;
    }
    if (getCoins() != other.getCoins()) {
        return getCoins() > other.getCoins();
    }
    return name < other.name;
}
