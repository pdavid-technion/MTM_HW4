#pragma once

#include <Player.h>
#include <../Events/Event.h>

class Character{
    public:
       
        virtual void reactToPotionsMerchant(Player& player) const = 0;
};

class Responsible: public Character{
    public:
        void reactToPotionsMerchant(Player& player) const override;
};

class RiskTaking : public Character {
    public:
        void reactToPotionsMerchant(Player& player) const override;
};