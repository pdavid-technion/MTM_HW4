#pragma once

#include "../Players/Player.h"
#include "Monster.h"
#include <vector>
#include "Event.h"

// class Event;

class MonsterEvent: public Event {
    private:
         std::unique_ptr<Monster> monster;  

    public:
        //MonsterEvent(std::unique_ptr<Monster> monster):monster(std::move(monster)){}
        explicit MonsterEvent(std::unique_ptr<Monster>);
        explicit MonsterEvent(Monster* monsterPtr); 
        explicit MonsterEvent(string& monsterName); 
        string handleEvent(Player& player) override;
        string getDescription() const override; 
         ~MonsterEvent() = default;
};