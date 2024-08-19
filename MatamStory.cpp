#include "Utilities.h"
#include "MatamStory.h"
#include "Events/MonsterEventFactory.h"
#include "Events/SolarEclipseFactory.h"
#include "Events/PotionsMerchantFactory.h"
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

std::shared_ptr<JobFactory> MatamStory::createJobFactory(const std::string& jobType) {
    if (jobType == "Warrior") {
        return std::make_shared<WarriorFactory>();
    } else if (jobType == "Archer") {
        return std::make_shared<ArcherFactory>();
    } else if (jobType == "Magician") {
        return std::make_shared<MagicianFactory>();
    }
    throw std::invalid_argument("Invalid job type");
}

std::shared_ptr<CharacterFactory> MatamStory::createCharacterFactory(const std::string& characterType) {
    if (characterType == "Responsible") {
        return std::make_shared<ResponsibleFactory>();
    } else if (characterType == "RiskTaker") {
        return std::make_shared<RiskTakingFactory>();
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
    // std::sort(players.begin(), players.end(),
    //     [](const Player& a, const Player& b) {
    //         return a < b; // Assuming Player class has a valid operator<
    //     });
    return players;
}

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
    : m_turnIndex(1) {

    std::string line;

    while (std::getline(eventsStream, line)) {
        //std::unique_ptr<Event> event;
        std::string firstWord = extractNextWord(line);

        if (firstWord == "Pack") {
            auto pack = parseMonsterPack(line);
            MonsterEventFactory factory(std::move(pack));
            eventsList.push_back(std::move(factory.createEvent()));
            //event = factory.createEvent();
        } else if (firstWord == "SolarEclipse") {
            SolarEclipseFactory factory;
            eventsList.push_back(std::move(factory.createEvent()));
            //event = factory.createEvent();
        } else if (firstWord == "PotionsMerchant") {
            PotionsMerchantFactory factory;
            eventsList.push_back(std::move(factory.createEvent()));
            //event = factory.createEvent();
        } else {
            auto monster = createMonsterFromType(firstWord);
            MonsterEventFactory factory(std::move(monster));
            eventsList.push_back(std::move(factory.createEvent()));
            //event = factory.createEvent();
        }

        //eventsList.push_back(std::move(event));
    }

    while (std::getline(playersStream, line)) {
        std::string name = extractNextWord(line);
        std::shared_ptr<JobFactory> jobFactory = createJobFactory(extractNextWord(line));
        std::shared_ptr<CharacterFactory> characterFactory = createCharacterFactory(extractNextWord(line));

        Player player(name, DEFAULT_LEVEL, DEFAULT_COINS, DEFAULT_HEALTH_POINTS, jobFactory, characterFactory);
        playersList.push_back(player);
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

    //auto sortedPlayers = sortPlayersByScore(std::move(playersList));
    unsigned int index = 1;
    //for (const auto& player : sortedPlayers) {
    for (const auto& player : playersList) {
        printLeaderBoardEntry(index, player);
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
    //auto sortedPlayers = sortPlayersByScore(std::move(playersList));

    //for (const auto& player : sortedPlayers) {
    for (const auto& player : playersList) {
        if (player.getLevel() >= WINNER_LEVEL) {
            printWinner(player);
            anyPlayerWinner = true;
            break;
        }
    }

    if (!anyPlayerWinner) {
        printNoWinners();
    }
}
