#pragma once

#include <Player.h>

class Character{
    public:
        virtual void reactToEvent(Event& event, Player& player) const = 0; //TODO - SHELLY - Add event+player
        virtual string printCharacterName() const = 0;
};

class Responsible: public Character{
    public:
        void reactToEvent(Event& event, Player& player) const override;
        string printCharacterName() const override{
            return "Responsible";
        }
};

class RiskTaking : public Character
{
public:
    void reactToEvent(Event &event, Player &player) const override;
    string printCharacterName() const override{
            return "RiskTaking";
        }
};