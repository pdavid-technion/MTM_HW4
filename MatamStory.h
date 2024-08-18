// #pragma once

// #include <iostream>
// #include <vector>
// #include "Players/Player.h"
// #include "Events/Event.h"
// #include "Events/MonsterPack.h"
// #include "Events/Factories/SnailFactory.h"
// #include "Events/Factories/BalrogFactory.h"
// #include "Events/Factories/BalrogFactory.h"
// #include "Players/Factories/WarriorFactory.h"


// class MatamStory{
// private:
//     unsigned int m_turnIndex;
//     std::vector<std::unique_ptr<Event>> eventsList;
//     std::vector<std::unique_ptr<Player>> playersList;
//     /**
//      * Playes a single turn for a player
//      *
//      * @param player - the player to play the turn for
//      *
//      * @return - void
//     */
//     void playTurn(Player& player);

//     /**
//      * Plays a single round of the game
//      *
//      * @return - void
//     */
//     void playRound();

//     /**
//      * Checks if the game is over
//      *
//      * @return - true if the game is over, false otherwise
//     */
//     bool isGameOver() const;

//     string getNextWord(string line);
//     std::unique_ptr<Monster> monsterFromString(string str);
//     std::unique_ptr<JobFactory> jobFactoryFromString(const std::string& jobType);
//     std::unique_ptr<CharacterFactory> characterFactoryFromString(const std::string& characterType);
//     std::unique_ptr<MonsterPack> parsePack(string& currLine);
//     std::vector<std::unique_ptr<Player>> sortPlayers(std::vector<std::unique_ptr<Player>> players);


// public:
//     /**
//      * Constructor of MatamStory class
//      *
//      * @param eventsStream - events input stream (file)
//      * @param playersStream - players input stream (file)
//      *
//      * @return - MatamStory object with the given events and players
//      *
//     */
//     MatamStory(std::istream& eventsStream, std::istream& playersStream);

//     /**
//      * Plays the entire game
//      *
//      * @return - void
//     */
//     void play();
// };

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Players/Player.h"
#include "Events/Event.h"
#include "Events/MonsterPack.h"
#include "Events/Factories/SnailFactory.h"
#include "Events/Factories/BalrogFactory.h"
#include "Events/Factories/SlimeFactory.h"
#include "Players/Factories/WarriorFactory.h"
#include "Players/Factories/ArcherFactory.h"
#include "Players/Factories/MagicianFactory.h"
#include "Players/Factories/ResponsibleFactory.h"
#include "Players/Factories/RiskTakingFactory.h"

class MatamStory {
private:
    unsigned int m_turnIndex;
    std::vector<std::unique_ptr<Event>> eventsList;
    std::vector<Player> playersList; // Changed from std::vector<std::unique_ptr<Player>> to std::vector<Player>

    void playTurn(Player& player);
    void playRound();
    bool isGameOver() const;

    std::string extractNextWord(std::string& line);
    std::unique_ptr<Monster> createMonsterFromType(const std::string& type);
    std::unique_ptr<JobFactory> createJobFactory(const std::string& jobType);
    std::unique_ptr<CharacterFactory> createCharacterFactory(const std::string& characterType);
    std::unique_ptr<MonsterPack> parseMonsterPack(std::string& line);
    std::vector<Player> sortPlayersByScore(std::vector<Player> players); // Updated to take and return std::vector<Player>

public:
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    void play();
};
