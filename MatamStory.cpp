
// #include "MatamStory.h"
// #include "./Events/MonsterPack.h"
// #include "Utilities.h"
// #include <memory>
// #include <algorithm>
// #include "./Events/Factories/MonsterFactory.h"
// #include "./Events/Factories/SingleMonsterFactory.h"
// #include "./Events/Factories/SnailFactory.h"
// #include "./Events/Factories/SlimeFactory.h"
// #include "./Events/Factories/BalrogFactory.h"
// #include "./Events/Factories/MonsterEventFactory.h"
// #include "./Events/Factories/PotionsMerchantFactory.h"
// #include "./Events/Factories/SolarEclipseFactory.h"
// #include "./Players/Factories/WarriorFactory.h"
// #include "./Players/Factories/MagicianFactory.h"
// #include "./Players/Factories/ArcherFactory.h"
// #include "./Players/Factories/ResponsibleFactory.h"
// #include "./Players/Factories/RiskTakingFactory.h"
// #include "./Players/Player.h"

// string MatamStory::getNextWord(string line)
// {
//     string word = line.substr(0, line.find(" "));
//     line.erase(0, line.find(" ") + 1);
//     return word;
// }

// std::unique_ptr<Monster> MatamStory::monsterFromString(string str)
// {
//     std::unique_ptr<Monster> monster = nullptr;
//     if (str == "Snail")
//     {
//         SnailFactory snailFactory;
//         monster = snailFactory.createMonster();
//     }
//     else if (str == "Balrog")
//     {
//         BalrogFactory balrogFactory;
//         monster = balrogFactory.createMonster();
//     }
//     else if (str == "Slime")
//     {
//         SlimeFactory slimeFactory;
//         monster = slimeFactory.createMonster();
//     }
//     return monster;
// }

// std::unique_ptr<JobFactory> MatamStory::jobFactoryFromString(const std::string& jobType) {
//     if (jobType == "Warrior") {
//         return std::make_unique<WarriorFactory>();
//     } else if (jobType == "Archer") {
//         return std::make_unique<ArcherFactory>();
//     } else if (jobType == "Magician") {
//         return std::make_unique<MagicianFactory>();
//     } else {
//         throw std::invalid_argument("Invalid job type");
//     }
// }

// std::unique_ptr<CharacterFactory> MatamStory::characterFactoryFromString(const std::string &characterType){
//      if (characterType == "Responsible") {
//         return std::make_unique<ResponsibleFactory>();
//     } else if (characterType == "RiskTaker") {
//         return std::make_unique<RiskTakingFactory>();
//     } else {
//         throw std::invalid_argument("Invalid character type");
//     }
// }

// MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream)
// {

//     string line;
//     /*===== TODO: Open and read events file =====*/

//     while (getline(eventsStream, line))
//     {
//         std::unique_ptr<Event> event;
//         string firstWord = getNextWord(line);



//         if (firstWord == "Pack") {
//             auto pack = parsePack(line);
//             MonsterEventFactory monsterEventFactory(std::move(pack));
//             event = monsterEventFactory.createEvent();
//         } 
//         else if (firstWord == "SolarEclipse")
//         {
//             SolarEclipseFactory solarEclipseFactory;
//             event = solarEclipseFactory.createEvent();
//         }
//         else if (firstWord == "PotionsMerchant")
//         {
//             PotionsMerchantFactory potionsMerchantFactory;
//             event = potionsMerchantFactory.createEvent();
//         }
//         else
//         {
//             std::unique_ptr<Monster> monster = monsterFromString(firstWord);
//             MonsterEventFactory monsterEventFactory(std::move(monster));
//             event = monsterEventFactory.createEvent();
//         }

//         eventsList.push_back(std::move(event));
//     }
//     /*==========================================*/

//     /*===== TODO: Open and Read players file =====*/

//     while (getline(playersStream, line))
//     {
//         string name = getNextWord(line);

//         std::unique_ptr<JobFactory> jobFactory = jobFactoryFromString(getNextWord(line));
//         std::unique_ptr<CharacterFactory> characterFactory = characterFactoryFromString(getNextWord(line));
//         std::unique_ptr<Player> player = std::make_unique<Player>(
//             name, 1, 10, 100, std::move(jobFactory), std::move(characterFactory));
//         playersList.push_back(std::move(player));
//     }

//     /*============================================*/

//     this->m_turnIndex = 1;
// }

// std::unique_ptr<MonsterPack> MatamStory::parsePack(string& currLine) {
//     int packSize = std::stoi(getNextWord(currLine));
//     auto pack = std::make_unique<MonsterPack>();

//     for (int i = 0; i < packSize; i++) {
//         string word = getNextWord(currLine);
//         if (word == "Pack") {
//             auto subPack = parsePack(currLine);
//             pack->addMonster(std::move(subPack));
//         } else {
//             auto monster = monsterFromString(word);
//             pack->addMonster(std::move(monster));
//         }
//     }

//     return pack;
// }

// std::vector<std::unique_ptr<Player>> MatamStory::sortPlayers(std::vector<std::unique_ptr<Player>> players) {
//     std::vector<std::unique_ptr<Player>> sortedPlayers;
//     sortedPlayers.reserve(players.size());

//     while (!players.empty()) {
//         auto it = std::max_element(players.begin(), players.end(),
//             [](const std::unique_ptr<Player>& a, const std::unique_ptr<Player>& b) {
//                 return *a < *b; // Define your own comparison logic
//             });

//         sortedPlayers.push_back(std::move(*it));
//         players.erase(it);
//     }

//     return sortedPlayers;
// }

// void MatamStory::playTurn(Player &player)
// {

//     /**
//      * Steps to implement (there may be more, depending on your design):
//      * 1. Get the next event from the events list
//      * 2. Print the turn details with "printTurnDetails"
//      * 3. Play the event
//      * 4. Print the turn outcome with "printTurnOutcome"
//      */
//     if (eventsList.empty()) {
//         return; // No events to process
//     }

//     // Get the current event in a circular manner
//     auto& event = eventsList[m_turnIndex % eventsList.size()];
    
//     // Print the turn details
//     printTurnDetails(m_turnIndex, player, *event);

//     // Apply the event to the player
//     std::string outcome = event->handleEvent(player);
    
//     // Print the outcome of the turn
//     printTurnOutcome(outcome);

//     m_turnIndex++;
// }

// void MatamStory::playRound()
// {

//     printRoundStart();

//     /*=====  Play a turn for each player =====*/
//     for (auto& player : playersList) {
//         if(player->isStillPlaying()){
//             playTurn(*player);
//         }
        
//     }
//     /*=============================================*/

//     printRoundEnd();

//     printLeaderBoardMessage();

//     /*===== Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/
//     std::vector<std::unique_ptr<Player>> sortedPlayers = sortPlayers(playersList);

//     unsigned int index = 1;
//     for (const auto& player : sortedPlayers) {
//         printLeaderBoardEntry(index, *player);
//         ++index;
//     }
//     /*=======================================================================================*/

//     printBarrier();
// }

// bool MatamStory::isGameOver() const
// {
//     bool allPlayersDead = true;
//     bool anyPlayerLevel10OrHigher = false;

//     // Check the status of each player
//     for (const auto& player : playersList) {
//         if (player->getLevel() >= 10) {
//             anyPlayerLevel10OrHigher = true;
//         }

//         if (player->getHealthPoints() > 0) {
//             allPlayersDead = false;
//         }
//     }

//     // The game is over if any player reached level 10 or if all players are dead
//     return anyPlayerLevel10OrHigher || allPlayersDead;
// }

// void MatamStory::play()
// {
//     printStartMessage();
//     /*===== Print start message entry for each player using "printStartPlayerEntry" =====*/
//     unsigned int index = 1;
//     for (const auto& player : playersList) {
//         printStartPlayerEntry(index, *player);
//         ++index;
//     }
//     /*=========================================================================================*/
   
//     printBarrier();

//     while (!isGameOver())
//     {
//         playRound();
//     }

//     printGameOver();
//     /*===== Print either a "winner" message or "no winner" message =====*/
//     std::vector<std::unique_ptr<Player>> sortedPlayers = sortPlayers(playersList);

//     bool anyPlayerWinner = false;
//     for (const auto& player : sortedPlayers) {
//         if (player->getLevel() >= 10) {
//             printWinner(*player);
//             anyPlayerWinner = true;
//             break; // Only one winner is needed, so break after finding the first
//         }
//     }

//     if (!anyPlayerWinner) {
//         printNoWinners();
//     }
//     /*========================================================================*/
    
// }

#include "MatamStory.h"
#include "Events/Factories/MonsterEventFactory.h"
#include "Events/Factories/SolarEclipseFactory.h"
#include "Events/Factories/PotionsMerchantFactory.h"
#include "Utilities.h"
#include <algorithm>
#include <memory>

std::string MatamStory::extractNextWord(std::string& line) {
    size_t pos = line.find(' ');
    std::string word = (pos == std::string::npos) ? line : line.substr(0, pos);
    line = (pos == std::string::npos) ? "" : line.substr(pos + 1);
    return word;
}

std::unique_ptr<Monster> MatamStory::createMonsterFromType(const std::string& type) {
    if (type == "Snail") {
        return SnailFactory{}.createMonster();
    } else if (type == "Balrog") {
        return BalrogFactory{}.createMonster();
    } else if (type == "Slime") {
        return SlimeFactory{}.createMonster();
    }
    return nullptr;
}

std::unique_ptr<JobFactory> MatamStory::createJobFactory(const std::string& jobType) {
    if (jobType == "Warrior") {
        return std::make_unique<WarriorFactory>();
    } else if (jobType == "Archer") {
        return std::make_unique<ArcherFactory>();
    } else if (jobType == "Magician") {
        return std::make_unique<MagicianFactory>();
    }
    throw std::invalid_argument("Invalid job type");
}

std::unique_ptr<CharacterFactory> MatamStory::createCharacterFactory(const std::string& characterType) {
    if (characterType == "Responsible") {
        return std::make_unique<ResponsibleFactory>();
    } else if (characterType == "RiskTaker") {
        return std::make_unique<RiskTakingFactory>();
    }
    throw std::invalid_argument("Invalid character type");
}

std::unique_ptr<MonsterPack> MatamStory::parseMonsterPack(std::string& line) {
    int packSize = std::stoi(extractNextWord(line));
    auto pack = std::make_unique<MonsterPack>();

    for (int i = 0; i < packSize; ++i) {
        std::string word = extractNextWord(line);
        if (word == "Pack") {
            auto subPack = parseMonsterPack(line);
            pack->addMonster(std::move(subPack));
        } else {
            auto monster = createMonsterFromType(word);
            pack->addMonster(std::move(monster));
        }
    }

    return pack;
}

std::vector<Player> MatamStory::sortPlayersByScore(std::vector<Player> players) {
    std::sort(players.begin(), players.end(),
        [](const Player& a, const Player& b) {
            return a < b; // Assuming Player class has a valid operator<
        });
    return players;
}

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
    : m_turnIndex(1) {

    std::string line;

    while (std::getline(eventsStream, line)) {
        std::unique_ptr<Event> event;
        std::string firstWord = extractNextWord(line);

        if (firstWord == "Pack") {
            auto pack = parseMonsterPack(line);
            MonsterEventFactory factory(std::move(pack));
            event = factory.createEvent();
        } else if (firstWord == "SolarEclipse") {
            SolarEclipseFactory factory;
            event = factory.createEvent();
        } else if (firstWord == "PotionsMerchant") {
            PotionsMerchantFactory factory;
            event = factory.createEvent();
        } else {
            auto monster = createMonsterFromType(firstWord);
            MonsterEventFactory factory(std::move(monster));
            event = factory.createEvent();
        }

        eventsList.push_back(std::move(event));
    }

    while (std::getline(playersStream, line)) {
        std::string name = extractNextWord(line);
        std::unique_ptr<JobFactory> jobFactory = createJobFactory(extractNextWord(line));
        std::unique_ptr<CharacterFactory> characterFactory = createCharacterFactory(extractNextWord(line));

        playersList.emplace_back(
            name, 1, 10, 100, std::move(jobFactory), std::move(characterFactory));
    }
}

void MatamStory::playTurn(Player& player) {
    if (eventsList.empty()) return;

    auto& event = eventsList[m_turnIndex % eventsList.size()];

    printTurnDetails(m_turnIndex, player, *event);

    std::string outcome = event->handleEvent(player);

    printTurnOutcome(outcome);

    ++m_turnIndex;
}

void MatamStory::playRound() {
    printRoundStart();

    for (auto& player : playersList) {
        if (player.isStillPlaying()) {
            playTurn(player);
        }
    }

    printRoundEnd();
    printLeaderBoardMessage();

    auto sortedPlayers = sortPlayersByScore(std::move(playersList));
    unsigned int index = 1;
    for (const auto& player : sortedPlayers) {
        printLeaderBoardEntry(index, player);
        ++index;
    }

    printBarrier();
}

bool MatamStory::isGameOver() const {
    bool anyPlayerLevel10OrHigher = std::any_of(playersList.begin(), playersList.end(),
        [](const Player& player) {
            return player.getLevel() >= 10;
        });

    bool allPlayersDead = std::all_of(playersList.begin(), playersList.end(),
        [](const Player& player) {
            return player.getHealthPoints() <= 0;
        });

    return anyPlayerLevel10OrHigher || allPlayersDead;
}

void MatamStory::play() {
    printStartMessage();

    unsigned int index = 1;
    for (const auto& player : playersList) {
        printStartPlayerEntry(index, player);
        ++index;
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    bool anyPlayerWinner = false;
    auto sortedPlayers = sortPlayersByScore(std::move(playersList));

    for (const auto& player : sortedPlayers) {
        if (player.getLevel() >= 10) {
            printWinner(player);
            anyPlayerWinner = true;
            break;
        }
    }

    if (!anyPlayerWinner) {
        printNoWinners();
    }
}
