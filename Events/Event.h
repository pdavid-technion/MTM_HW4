#pragma once

#include "../Players/Player.h"
#include <Monster.h>

class Event {
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    string getDescription() const; //DAVID

    virtual void handleEvent(Player& player) = 0;
};

class MonsterEvent: public Event {
    private:
         std::unique_ptr<Monster> monster;  

    public:
        MonsterEvent(std::unique_ptr<Monster> monster):monster(std::move(monster)){}
        void handleEvent(Player& player) override;  
};

class SolarEclipse: public Event {
        
    public:
        void handleEvent(Player& player) override;  
};

class PotionsMerchant: public Event {
        
    public:
        void handleEvent(Player& player) override;  
};