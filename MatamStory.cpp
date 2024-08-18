
#include "MatamStory.h"
#include <MonsterPack.h>
#include "Utilities.h"
#include <memory>
#include <algorithm>
#include <../Events/Factories/MonsterFactory.h>
#include <../Events/Factories/SingleMonsterFactory.h>
#include <../Events/Factories/SnailFactory.h>
#include <../Events/Factories/SlimeFactory.h>
#include <../Events/Factories/BalrogFactory.h>
#include <../Events/Factories/MonsterEventFactory.h>
#include <../Events/Factories/PotionsMerchantFactory.h>
#include <../Events/Factories/SolarEclipseFactory.h>
#include <../Players/Factories/WarriorFactory.h>
#include <../Players/Factories/MagicianFactory.h>
#include <../Players/Factories/ArcherFactory.h>
#include <../Players/Factories/ResponsibleFactory.h>
#include <../Players/Factories/RiskTakingFactory.h>

string getNextWord(string line)
{
    string word = line.substr(0, line.find(" "));
    line.erase(0, line.find(" ") + 1);
    return word;
}

std::shared_ptr<Monster> monsterFromString(string str)
{
    std::shared_ptr<Monster> monster = nullptr;
    if (str == "Snail")
    {
        SnailFactory snailFactory;
        monster = snailFactory.createMonster();
    }
    else if (str == "Balrog")
    {
        BalrogFactory balrogFactory;
        monster = balrogFactory.createMonster();
    }
    else if (str == "Slime")
    {
        SlimeFactory slimeFactory;
        monster = slimeFactory.createMonster();
    }
    return monster;
}

std::unique_ptr<JobFactory> jobFactoryFromString(const std::string& jobType) {
    if (jobType == "Warrior") {
        return std::make_unique<WarriorFactory>();
    } else if (jobType == "Archer") {
        return std::make_unique<ArcherFactory>();
    } else if (jobType == "Magician") {
        return std::make_unique<MagicianFactory>();
    } else {
        throw std::invalid_argument("Invalid job type");
    }
}

std::unique_ptr<CharacterFactory> characterFactoryFromString(const std::string &characterType){
     if (characterType == "Responsible") {
        return std::make_unique<ResponsibleFactory>();
    } else if (characterType == "RiskTaker") {
        return std::make_unique<RiskTakingFactory>();
    } else {
        throw std::invalid_argument("Invalid character type");
    }
}

MatamStory::MatamStory(std::istream &eventsStream, std::istream &playersStream)
{

    string line;
    string text;
    string word;
    /*===== TODO: Open and read events file =====*/
    while (getline(eventsStream, line))
    {   
        text += line + " ";
    }
    while ((word = getNextWord(text)) != "")
    {
        std::shared_ptr<Event> event;
        if (word == "Pack")
        {
            auto pack = parsePack(text);
            MonsterEventFactory monsterEventFactory = MonsterEventFactory(pack);
            event = monsterEventFactory.createEvent();
        }
        else if (word == "SolarEclipse")
        {
            SolarEclipseFactory solarElipseFactory;
            event = solarElipseFactory.createEvent();
        }
        else if (word == "PotionsMerchant")
        {
            PotionsMerchantFactory potionsMerchantFactory;
            event = potionsMerchantFactory.createEvent();
        }
        else
        {
            std::shared_ptr<Monster> monster = monsterFromString(firstWord);
            MonsterEventFactory monsterEventFactory(monster);
            event = monsterEventFactory.createEvent();
        }

        eventsList.push_back(event);
    }
    /*==========================================*/

    /*===== TODO: Open and Read players file =====*/

    while (getline(playersStream, line))
    {
        string name = getNextWord(line);

        std::unique_ptr<JobFactory> jobFactory = jobFactoryFromString(getNextWord(line));
        std::unique_ptr<CharacterFactory> characterFactory = characterFactoryFromString(getNextWord(line));
        std::shared_ptr<Player> player = std::make_shared<Player>(
            name, 1, 10, 100, 10, std::move(jobFactory), std::move(characterFactory));
        playersList.push_back(player);
    }

    /*============================================*/

    this->m_turnIndex = 1;
}

std::shared_ptr<MonsterPack> MatamStory::parsePack(string& currLine) {
    int packSize = std::stoi(getNextWord(currLine));
    auto pack = std::make_shared<MonsterPack>();

    for (int i = 0; i < packSize; i++) {
        string word = getNextWord(currLine);
        if (word == "Pack") {
            auto subPack = parsePack(currLine);
            pack->addMonster(subPack);
        } else {
            auto monster = monsterFromString(word);
            pack->addMonster(monster);
        }
    }

    return pack;
}

void MatamStory::playTurn(Player &player)
{

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
     */
    if (eventsList.empty()) {
        return; // No events to process
    }

    // Get the current event in a circular manner
    auto& event = eventsList[m_turnIndex % eventsList.size()];
    
    // Print the turn details
    printTurnDetails(m_turnIndex, player, *event);

    // Apply the event to the player
    std::string outcome = event->handleEvent(player);
    
    // Print the outcome of the turn
    printTurnOutcome(outcome);

    m_turnIndex++;
}

void MatamStory::playRound()
{

    printRoundStart();

    /*=====  Play a turn for each player =====*/
    for (auto& player : playersList) {
        if(player->isStillPlaying()){
            playTurn(*player);
        }
        
    }
    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/
    std::vector<std::shared_ptr<Player>> sortedPlayers(playersList.begin(), playersList.end());

    std::sort(sortedPlayers.begin(), sortedPlayers.end(), 
    [](const std::shared_ptr<Player>& a, const std::shared_ptr<Player>& b) {
        return *a < *b; // Use the overloaded operator< for comparison
    });

    unsigned int index = 1;
    for (const auto& player : sortedPlayers) {
        printLeaderBoardEntry(index, *player);
        ++index;
    }
    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const
{
    bool allPlayersDead = true;
    bool anyPlayerLevel10OrHigher = false;

    // Check the status of each player
    for (const auto& player : playersList) {
        if (player->getLevel() >= 10) {
            anyPlayerLevel10OrHigher = true;
        }

        if (player->getHealthPoints() > 0) {
            allPlayersDead = false;
        }
    }

    // The game is over if any player reached level 10 or if all players are dead
    return anyPlayerLevel10OrHigher || allPlayersDead;
}

void MatamStory::play()
{
    printStartMessage();
    /*===== Print start message entry for each player using "printStartPlayerEntry" =====*/
    unsigned int index = 1;
    for (const auto& player : playersList) {
        printStartPlayerEntry(index, *player);
        ++index;
    }
    /*=========================================================================================*/
   
    printBarrier();

    while (!isGameOver())
    {
        playRound();
    }

    printGameOver();
    /*===== Print either a "winner" message or "no winner" message =====*/
    std::vector<std::shared_ptr<Player>> sortedPlayers(playersList.begin(), playersList.end());

    std::sort(sortedPlayers.begin(), sortedPlayers.end(), 
    [](const std::shared_ptr<Player>& a, const std::shared_ptr<Player>& b) {
        return *a < *b; // Use the overloaded operator< for comparison
    });

    bool anyPlayerWinner = false;
    for (const auto& player : sortedPlayers) {
        if (player->getLevel() >= 10) {
            printWinner(*player);
            anyPlayerWinner = true;
            break; // Only one winner is needed, so break after finding the first
        }
    }

    if (!anyPlayerWinner) {
        printNoWinners();
    }
    /*========================================================================*/
    
}
