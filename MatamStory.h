
#pragma once

#include <iostream>
#include <vector>
#include "Players/Player.h"
#include "Events/Event.h"
#include "Events/Factories/SnailFactory.h"
#include "Events/Factories/BalrogFactory.h"
#include "Events/Factories/BalrogFactory.h"
#include "Players/Factories/WarriorFactory.h"




class MatamStory{
private:
    unsigned int m_turnIndex;
    std::vector<std::shared_ptr<Event>> eventsList;
    std::vector<std::shared_ptr<Event>> playersList;
    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn(Player& player);

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

    string getNextWord(string str);
    std::shared_ptr<Monster> monsterFromString(string str);
    std::unique_ptr<Job> jobFromString(string str);
    std::unique_ptr<Character> characterFromString(string str);
    std::unique_ptr<JobFactory> jobFactoryFromString(const std::string& jobType);
    std::unique_ptr<CharacterFactory> characterFactoryFromString(const std::string& characterType);

public:
    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};
