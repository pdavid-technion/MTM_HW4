#pragma once

#include "../Players/Player.h"
#include "Monster.h"
#include <vector>
#include "Event.h"

class MonsterEvent: public Event {
    private:
         std::unique_ptr<Monster> monster;  

    public:
        //MonsterEvent(std::unique_ptr<Monster> monster):monster(std::move(monster)){}
        explicit MonsterEvent(Monster* monster); 
        string handleEvent(Player& player) override;
        string getDescription() const override; 
         ~MonsterEvent() = default;
};