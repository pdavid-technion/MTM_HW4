#pragma once

#include <Player.h>

class Character{
    public:
        virtual void reactToEvent(Event& event, Player& player) const = 0; //TODO - SHELLY - Add event+player
};

class Responsible: public Character{
    public:
        void reactToEvent(Event& event, Player& player) const override;
};

class RiskTaking : public Character
{
public:
    void reactToEvent(Event &event, Player &player) const override;
};