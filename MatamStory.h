#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Players/Player.h"
#include "Events/Event.h"
#include "Events/MonsterPack.h"
#include "Events/SnailFactory.h"
#include "Events/BalrogFactory.h"
#include "Events/SlimeFactory.h"
#include "Players/WarriorFactory.h"
#include "Players/ArcherFactory.h"
#include "Players/MagicianFactory.h"
#include "Players/ResponsibleFactory.h"
#include "Players/RiskTakingFactory.h"

class Player;

class MatamStory {
private:
    unsigned int m_turnIndex;
    std::vector<std::unique_ptr<Event>> eventsList;
    std::vector<Player> playersList;

    void playTurn(Player& player);
    void playRound();
    bool isGameOver() const;
    void readEventsFile(std::istream& eventsStream);
    void readPlayersFile(std::istream& playersStream);

    std::string extractNextWord(std::string& line);
    std::unique_ptr<Monster> createMonsterFromType(const std::string& type);
    std::shared_ptr<JobFactory> createJobFactory(const std::string& jobType);
    std::shared_ptr<CharacterFactory> createCharacterFactory(const std::string& characterType);
    std::unique_ptr<MonsterPack> parseMonsterPack(std::string& line);
    std::vector<Player*> sortPlayersByScore();

public:
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    void play();
};
