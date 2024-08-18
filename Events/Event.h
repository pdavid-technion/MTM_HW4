#pragma once

#include "../Players/Player.h"
#include <Monster.h>
#include <vector>

class Event {
public:
    /**
     * Gets the description of the event
     *
     * @return - the description of the event
    */
    virtual string getDescription() const;

    virtual string handleEvent(Player& player) = 0;
};

class MonsterEvent: public Event {
    private:
         std::unique_ptr<Monster> monster;  

    public:
        MonsterEvent(std::unique_ptr<Monster> monster):monster(std::move(monster)){}
        string handleEvent(Player& player) override;
        string getDescription() const override;  
};

class SolarEclipse: public Event {
        
    public:
        string handleEvent(Player& player) override;
        string getDescription() const override;   
};

class PotionsMerchant: public Event {
        
    public:
        string handleEvent(Player& player) override;  
        string getDescription() const override; 
};