// #include "Player.h"
// #include "./Factories/JobFactory.h"
// #include "./Job/Job.h"
// #include "./Character/Character.h"
// #include <string>


// Player::Player( std::string name,
//                 int level = 1,
//                 int force = 10,
//                 int healthPoints = 100,
//                 std::unique_ptr<JobFactory> jobFactory,
//                 std::unique_ptr<CharacterFactory> characterFactory):
//                 name(name),
//                 level(level),
//                 force(force),
//                 healthPoints(healthPoints),
//                 job(jobFactory->createJob()),
//                 character(characterFactory->createCharacter()) {}

// string Player::getDescription() const{
//     string str = name + ", " + job->printJobName() + " with " + character->printCharacterName() +
//     " (" + std::to_string(level) + ", " + std::to_string(force) + ")";
//     return str;
// } 

// string Player::getName() const{
//     return name;
// }

// int Player::getLevel() const{
//     return level;
// }

// int Player::getForce() const{
//     return force;
// }

// int Player::getHealthPoints() const{
//    return healthPoints;
// }

// int Player::getCoins() const{
//     return this->job->getCoins();
// }

// int Player::getCombatPower() const{
//     return this->job->calculateCombatPower(this->force, this->level);
// }

// void Player::winMonster( int loot ) {
//         this->level += 1;
//         this->job->setCoins(this->getCoins()+loot);
// }

// void Player::loseToMonster( int damage ){
//     this->healthPoints = std::max(0, this->healthPoints - damage);
// }

// void Player::closeEncounter(){
//     this->healthPoints = std::max(0, this->healthPoints - 10 ); //TODO - SHELLY - consts
// }

// void Player::applyDarknessConfusion(){
//     this->healthPoints = std::max(0, this->healthPoints-1);
// }

// void Player::applyDarknessMagic(){
//     this->healthPoints = std::min(this->getMaxHealthPoints(), this->healthPoints+1);
// }

// int Player::getMaxHealthPoints(){
//      return this->job->getMaxHealthPoints();
// }

// void Player::buyPotions(int potionAmount){
//     this->healthPoints = std::max(this->getMaxHealthPoints(), this->getHealthPoints() + potionAmount * 10 );
//     this->job->setCoins(this->getCoins() - potionAmount * 5);
// }

// string Player::combatMonster( Monster& monster){
//     return this->job->combatMonster(*this, monster);
// }

// string Player::reactToSolarEclipse(){
//     return this->job->reactToSolarEclipse(*this);
// }

// string Player::reactToPotionsMerchant(){
//     this->character->reactToPotionsMerchant(*this);
// }

// //bool Player::operator<(const Player& other) const {
// bool Player::operator<(Player const& other) const {
//     if (level != other.level) {
//         return level > other.level;
//     }

//     if (getCoins() != other.getCoins()) {
//         return getCoins() > other.getCoins();
//     }

//     return name < other.name;
// }

// bool Player::isStillPlaying() const{
//     return this->getHealthPoints() > 0;
// }


#include "Player.h"
#include "./Factories/JobFactory.h"
#include "./Job/Job.h"
#include "./Character/Character.h"
#include <string>

Player::Player(std::string name,
                int level,
                int force,
                int healthPoints,
                std::unique_ptr<JobFactory> jobFactory,
                std::unique_ptr<CharacterFactory> characterFactory)
                : name(name),
                  level(level),
                  force(force),
                  healthPoints(healthPoints),
                  job(jobFactory ? jobFactory->createJob() : nullptr),
                  character(characterFactory ? characterFactory->createCharacter() : nullptr) {}

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
    this->healthPoints = std::max(0, this->healthPoints - 10); //TODO - SHELLY - consts
}

void Player::applyDarknessConfusion() {
    this->healthPoints = std::max(0, this->healthPoints - 1);
}

void Player::applyDarknessMagic() {
    this->healthPoints = std::min(this->getMaxHealthPoints(), this->healthPoints + 1);
}

int Player::getMaxHealthPoints() {
    return this->job->getMaxHealthPoints();
}

void Player::buyPotions(int potionAmount) {
    this->healthPoints = std::min(this->getMaxHealthPoints(), this->getHealthPoints() + potionAmount * 10);
    this->job->setCoins(this->getCoins() - potionAmount * 5);
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
