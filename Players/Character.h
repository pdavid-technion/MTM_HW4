#pragma once

#include <Player.h>
#include <../Events/Event.h>

class Character{
    public:
        virtual void reactToSolarEclipse(Event& event, Player& player) const = 0;
        virtual void reactToPotionsMerchant(Event& event, Player& player) const = 0;
};

class Responsible: public Character{
    public:
        void reactToSolarEclipse(Event& event, Player& player) const override;
        void reactToPotionsMerchant(Event& event, Player& player) const override;
};

class RiskTaking : public Character
{
public:
    void reactToSolarEclipse(Event &event, Player &player) const override;
    void reactToPotionsMerchant(Event& event, Player& player) const override;
};