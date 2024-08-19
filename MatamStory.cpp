#include "Utilities.h"
#include "MatamStory.h"
#include "Events/MonsterEventFactory.h"
#include "Events/SolarEclipseFactory.h"
#include "Events/PotionsMerchantFactory.h"
#include <algorithm>
#include <memory>
#include <string>
#include "Players/PlayerConsts.h"

 std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \n\r\t");
    size_t last = str.find_last_not_of(" \n\r\t");
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

std::string MatamStory::extractNextWord(std::string& line) {
    // size_t pos = line.find(' ');
    // std::string word = (pos == std::string::npos) ? line : line.substr(0, pos);
    // line = (pos == std::string::npos) ? "" : line.substr(pos + 1);
    // return word;

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
    if (!type.compare("Snail")) {
        return SnailFactory{}.createMonster();
    } else if (!type.compare("Balrog")) {
        return BalrogFactory{}.createMonster();
    } else if (!type.compare("Slime")) {
        return SlimeFactory{}.createMonster();
    }
    return nullptr;
}

std::shared_ptr<JobFactory> MatamStory::createJobFactory(const std::string& jobType) {
    if (!jobType.compare("Warrior")) {
        return std::make_shared<WarriorFactory>();
    } else if (!jobType.compare("Archer")) {
        return std::make_shared<ArcherFactory>();
    } else if (!jobType.compare("Magician")) {
        return std::make_shared<MagicianFactory>();
    }
    throw std::invalid_argument("Invalid job type");
}

std::shared_ptr<CharacterFactory> MatamStory::createCharacterFactory(const std::string& characterType) {
    if (!characterType.compare("Responsible")) {

        return std::make_shared<ResponsibleFactory>();
    } else if (!characterType.compare("RiskTaking")) {

        return std::make_shared<RiskTakingFactory>();
    }
    throw std::invalid_argument("Invalid character type");
}

std::unique_ptr<MonsterPack> MatamStory::parseMonsterPack(std::string& line) {
    int packSize = std::stoi(extractNextWord(line));
    auto pack = std::make_unique<MonsterPack>();
    for (int i = 0; i < packSize; ++i) {
        std::string word = extractNextWord(line);
        if (!word.compare("Pack")) {
            auto subPack = parseMonsterPack(line);
            pack->addMonster(std::move(subPack));
        } else {
            auto monster = createMonsterFromType(word);
            pack->addMonster(std::move(monster));
        }
    }

    return pack;
}

std::vector<Player*> MatamStory::sortPlayersByScore(std::vector<Player> players) {
    std::vector<Player*> sortedPlayers;
    for( auto& player: playersList){
        sortedPlayers.push_back(&player);
    }

    std::sort(sortedPlayers.begin(), sortedPlayers.end(),
    [] (Player* a, Player* b){ 
        return ( *b < *a ); 
    });

    return sortedPlayers;
}

void MatamStory::readEventsFile(std::istream& eventsStream)
{
    std::string line;
    MonsterEventFactory factory;// = new MonsterEventFactory();

    while (std::getline(eventsStream, line)) {
        
        // std::string firstWord = extractNextWord(line);

        // if (!firstWord.compare("Pack")) {
        //     auto pack = parseMonsterPack(line);
        //     MonsterEventFactory factory(std::move(pack));
        //     eventsList.push_back(std::move(factory.createEvent()));

        // } else if (!firstWord.compare("SolarEclipse")) {

        //     SolarEclipseFactory factory;

        //     eventsList.push_back(std::move(factory.createEvent()));


        // } else if (!firstWord.compare("PotionsMerchant")) {

        //     PotionsMerchantFactory factory;

        //     eventsList.push_back(std::move(factory.createEvent()));


        // } else if(firstWord == "Snail"  || (!firstWord.compare("Slime")) || (!firstWord.compare("Balrog"))) {
         
        //     auto monster = createMonsterFromType(firstWord);
        //     //MonsterEventFactory factory(std::move(monster));
        //     auto a = std::make_unique<MonsterEvent>(std::make_unique<Snail>());
        //     std::cout << "a->getDamage() "<< a->getDescription() << std::endl;
        //     // eventsList.push_back(std::make_unique<MonsterEvent>(std::move(monster)));
        //     eventsList.push_back(std::move(a));
        //     //auto event = factory.createEvent();
        // }
        // else {
        //     throw std::invalid_argument("Invalid Event File");
        // }

        eventsList.push_back(factory.createShulaEvent(line));
    }

    if(eventsList.size() < 2 ){
        throw std::invalid_argument("Invalid Event File");
    }
}

void MatamStory::readPlayersFile(std::istream& playersStream)
{
    std::string line;

    while (std::getline(playersStream, line)) {

        std::string job, character;
        std::string name = extractNextWord(line);

        job = extractNextWord(line);

        std::shared_ptr<JobFactory> jobFactory = nullptr;
        std::shared_ptr<CharacterFactory> characterFactory = nullptr;

        if(!job.compare("Warrior") || !job.compare("Magician") || !job.compare("Archer")) {

            jobFactory = createJobFactory(job);

        }
        else {
            throw std::invalid_argument("Invalid Players File");
        }

        character = extractNextWord(line);

        if(!character.compare("Responsible") || !character.compare("RiskTaking")) {

            characterFactory = createCharacterFactory(character);

        }
        else {
            throw std::invalid_argument("Invalid Players File");
        }
        Player player(name, DEFAULT_LEVEL, DEFAULT_COINS, DEFAULT_HEALTH_POINTS, jobFactory, characterFactory);
        playersList.push_back(player);
    }

    if(playersList.size() > 6 || playersList.size() < 2 ){
        throw std::invalid_argument("Invalid Players File");
    }
}

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream)
    : m_turnIndex(1) {
        MatamStory::readEventsFile(eventsStream);
        MatamStory::readPlayersFile(playersStream);
    }

void MatamStory::playTurn(Player& player) {
    if (eventsList.empty()) return;

    auto& event = eventsList[m_turnIndex % eventsList.size()];

     if (!event) {
        std::cout << "Error: event is null." << std::endl;
        
    }

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
    // for (const auto& player : playersList) {
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
    auto sortedPlayers = sortPlayersByScore(std::move(playersList));

    for (const auto& player : sortedPlayers) {
    // for (const auto& player : playersList) {
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
