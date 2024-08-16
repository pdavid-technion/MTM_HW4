
#include "MatamStory.h"

#include "Utilities.h"


string getNextWord(string str) {
    string word = line.substr(0, line.find(" "));
    str.erase(0, line.find(" ") + 1);
    retrun word;
}

std::shared_ptr<Monster> monsterFromString(string str)
{
    std::shared_ptr<Monster> monster = nullptr;
    if(str == "Snail") {
        monster = MonsterFactory::SingleMonsterFactory::SnailFactory::createMonster();
    }
    else if(str == "Balrog") {
        monster = MonsterFactory::SingleMonsterFactory::BalrogFactory::createMonster();
    }
    else if(str == "Slime") {
        monster = MonsterFactory::SingleMonsterFactory::SlimeFactory::createMonster();
    }
    return monster;
}

std::unique_ptr<Job> jobFromString(string str){
    std::unique_ptr<Job> job = nullptr;
    if(str == "Warrior") {
        job = JobFactory::WarriorFactory::createJob();
    }
    else if(str == "Magician") {
        job = JobFactory::MagicianFactory::createJob();
    }
    else if(str == "Archer") {
        job = JobFactory::ArcherFactory::createJob();
    }
    return job;
}

std::unique_ptr<Character> characterFromString(string str){
    std::unique_ptr<Character> character = nullptr;
    if(str == "Responsible") {
        character = CharacterFactory::ResponsibleFactory::createCharacter();
    }
    else if(str == "RiskTaking") {
        character = CharacterFactory::RiskTakingFactory::createCharacter();
    }
    return character;
}

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) {

    string line;
    /*===== TODO: Open and read events file =====*/
    
    while (getline(eventsStream, line)) {
        std::shared_ptr<Event> event;
        string firstWord = getNextWord(line);
        if(firstWord == "Pack") {
            std::shared_ptr<Monster> pack, monster;
            int packSize = stoi(getNextWord(line));
            for(int i=0; i < packSize; i++) {
                if(monster = monsterFromString(getNextWord(line))) {                    
                    pack.addMonster(monster);
                }
            }
            event = Event::MonsterEvent(pack);
        }
        else if(firstWord == "SolarEclipse") {
           event = Event::SolarEclipse();
        }
        else if(firstWord == "PotionsMerchant") {
            event = Event::PotionsMerchant();
        }
        else {
            std::shared_ptr<Monster> monster = monsterFromString(firstWord);
            event = Event::MonsterEvent(monster);
        }

        eventsList.push_back(event);
    }
    /*==========================================*/


    /*===== TODO: Open and Read players file =====*/


    while (getline(playersStream, line)) {
        string name = getNextWord(line);
        std::unique_ptr<Job> job = jobFromString(getNextWord(line));
        std::unique_ptr<Character> character = characterFromString(getNextWord(line));
        std::shared_ptr<Player> player = Player(name, job, character);
        playersList.push_back(player);
    }
    

    /*============================================*/


    this->m_turnIndex = 1;
}

void MatamStory::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */

    m_turnIndex++;
}

void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}


