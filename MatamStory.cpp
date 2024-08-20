#include "Utilities.h"
#include "MatamStory.h"
#include "Events/MonsterEvent.h"
#include "Events/SolarEclipse.h"
#include "Events/PotionsMerchant.h"
#include <algorithm>
#include <memory>
#include <string>
#include "Players/PlayerConsts.h"

 std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \n\r\t");
    size_t last = str.find_last_not_of(" \n\r\t");
    return (first == std::string::npos || last == std::string::npos) ? "" : 
            str.substr(first, last - first + 1);
}

bool isAlphaString(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](unsigned char c) {
        return std::isalpha(c);
    });
}

std::string MatamStory::extractNextWord(std::string& line) {

      line = trim(line);

    // Find the position of the first space or newline
    size_t pos = line.find_first_of(" \n");

    // Extract the word
    std::string word = (pos == std::string::npos) ? line : line.substr(0, pos);

    // Update the line to remove the extracted word
    line = (pos == std::string::npos) ? "" : line.substr(pos + 1);

    // Trim the line again for the next extraction
    line = trim(line);

    return word;
}

std::unique_ptr<Monster> MatamStory::createMonsterFromType(const std::string& type) {
    if (!type.compare(SNAIL)) {
        return SnailFactory{}.createMonster();
    } else if (!type.compare(BALROG)) {
        return BalrogFactory{}.createMonster();
    } else if (!type.compare(SLIME)) {
        return SlimeFactory{}.createMonster();
    }
    return nullptr;
}

std::shared_ptr<JobFactory> MatamStory::createJobFactory(const std::string& jobType) {
    if (!jobType.compare(WARRIOR)) {
        return std::make_shared<WarriorFactory>();
    } else if (!jobType.compare(ARCHER)) {
        return std::make_shared<ArcherFactory>();
    } else if (!jobType.compare(MAGICIAN)) {
        return std::make_shared<MagicianFactory>();
    }
    throw std::invalid_argument("Invalid job type");
}

std::shared_ptr<CharacterFactory> MatamStory::createCharacterFactory(const string& characterType){
    if (!characterType.compare(RESPONSIBLE)) {

        return std::make_shared<ResponsibleFactory>();
    } else if (!characterType.compare(RISK_TAKING)) {

        return std::make_shared<RiskTakingFactory>();
    }
    throw std::invalid_argument("Invalid character type");
}

std::unique_ptr<MonsterPack> MatamStory::parseMonsterPack(std::istream& eventsStream) {
    unsigned int packSize;
    if(eventsStream >> packSize){
        auto pack = std::make_unique<MonsterPack>();
    } else {
       throw std::invalid_argument(EVENT_FILE_ERROR); 
    }

    auto pack = std::make_unique<MonsterPack>();

    for (unsigned int i = 0; i < packSize; ++i) {
        std::string word;
        eventsStream >> word;

        // Trim and check if the word is empty
        if (word.empty()) {
            throw std::invalid_argument(EVENT_FILE_ERROR);
        }

        if (word == PACK) {
            // Recursively parse a subPack
            auto subPack = parseMonsterPack(eventsStream);
            pack->addMonster(std::move(subPack));

        } else if (word == SNAIL || word == BALROG || word == SLIME) {
            // Create a monster from the type
            auto monster = createMonsterFromType(word);
            if (monster) {
                pack->addMonster(std::move(monster));
            } else {
                throw std::invalid_argument(EVENT_FILE_ERROR);
            }
        } else {
           throw std::invalid_argument(EVENT_FILE_ERROR);
        }
    }

    return pack;
}

std::vector<Player*> MatamStory::sortPlayersByScore() {
    std::vector<Player*> sortedPlayers;
    for( auto& player: playersList){
        sortedPlayers.push_back(&player);
    }

    std::sort(sortedPlayers.begin(), sortedPlayers.end(),
    [] (Player* a, Player* b){ 
        return ( *a > *b ); 
    });

    return sortedPlayers;
}


void MatamStory::readEventsFile(std::istream& eventsStream){
     std::string word;
    while (eventsStream >> word) {
        if (word == PACK) {
            auto pack = parseMonsterPack(eventsStream);
            eventsList.push_back(std::make_unique<MonsterEvent>(std::move(pack)));
        } else if (word == SOLAR_ECLIPSE) {
            eventsList.push_back(std::make_unique<SolarEclipse>());
        } else if (word == POTIONS_MERCHANT) {
            eventsList.push_back(std::make_unique<PotionsMerchant>());
        } else if (word == SNAIL || word == BALROG || word == SLIME) {
            eventsList.push_back(std::make_unique<MonsterEvent>(word));
        } else {
            throw std::invalid_argument(EVENT_FILE_ERROR);
        }
    }

    // Ensure there are enough events
    if (eventsList.size() < 2) {
        throw std::invalid_argument(EVENT_FILE_ERROR);
    }
}

void MatamStory::readPlayersFile(std::istream& playersStream){

    std::string name, job, character;

    while (playersStream >> name >> job >> character) {
        // Validate the player's name
        if (name.length() < 3 || name.length() > 15 || !isAlphaString(name)) {
            throw std::invalid_argument(PLAYER_FILE_ERROR);
        }

        // Validate and create the job factory
        std::shared_ptr<JobFactory> jobFactory = nullptr;
        if (job == WARRIOR || job == MAGICIAN || job == ARCHER) {
            jobFactory = createJobFactory(job);
        } else {
            throw std::invalid_argument(PLAYER_FILE_ERROR);
        }

        // Validate and create the character factory
        std::shared_ptr<CharacterFactory> characterFactory = nullptr;
        if (character == RESPONSIBLE || character == RISK_TAKING) {
            characterFactory = createCharacterFactory(character);
        } else {
            throw std::invalid_argument(PLAYER_FILE_ERROR);
        }

        // Create and store the player
        Player player(name, jobFactory, characterFactory);
        playersList.push_back(player);
    }

    // Ensure the correct number of players
    if (playersList.size() > 6 || playersList.size() < 2) {
        throw std::invalid_argument(PLAYER_FILE_ERROR);
    }
}

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
    : m_turnIndex(1) {
        // MatamStory::readEventsFile(eventsStream);
        // MatamStory::readPlayersFile(playersStream);
         try {
        // Attempt to read the events file first
        MatamStory::readEventsFile(eventsStream);
        } catch (const std::invalid_argument& e) {
        // If an exception occurs while reading the events, rethrow it
        if (std::string(e.what()) == EVENT_FILE_ERROR) {
            throw;  // Re-throw the exception so that it takes precedence
        }
        // Otherwise, continue to check for the player file error
    }

    // If no exception occurred (or a non-event exception occurred), continue
    MatamStory::readPlayersFile(playersStream);
}

void MatamStory::playTurn(Player& player) {
    if (eventsList.empty()) return;

    auto& event = eventsList[(m_turnIndex - 1) % eventsList.size()];

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

    auto sortedPlayers = sortPlayersByScore();
    unsigned int index = 1;
    for (const auto& player : sortedPlayers) {
        printLeaderBoardEntry(index, *player);
        ++index;
    }

    printBarrier();
}

bool MatamStory::isGameOver() const {
        bool allPlayersDead = true;
        bool anyPlayerWinner = false;

    // Check the status of each player
    for (const auto& player : playersList) {
        if (player.getLevel()  >= WINNER_LEVEL) {
            anyPlayerWinner = true;
        }

        if (player.isStillPlaying()) {
            allPlayersDead = false;
        }
    }

    // The game is over if any player reached level 10 or if all players are dead
    return anyPlayerWinner || allPlayersDead;
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
    auto sortedPlayers = sortPlayersByScore();

    for (const auto& player : sortedPlayers) {
        if (player->getLevel() >= WINNER_LEVEL) {
            printWinner(*player);
            anyPlayerWinner = true;
            break;
        }
    }

    if (!anyPlayerWinner) {
        printNoWinners();
    }
}
