#pragma once

#include "../Players/Player.h"
#include "Monster.h"
#include "MonsterPack.h"
#include <vector>
#include "Event.h"

// class Event;

class MonsterEvent: public Event {
    private:
         std::unique_ptr<Monster> monster;  

    public:
        explicit MonsterEvent(std::unique_ptr<Monster> newMonster);
        explicit MonsterEvent(std::unique_ptr<MonsterPack> newMonsterPack);
        explicit MonsterEvent(Monster* monsterPtr); 
        explicit MonsterEvent(string& monsterName); 
        string handleEvent(Player& player) override;
        string getDescription() const override; 
         ~MonsterEvent() = default;
};