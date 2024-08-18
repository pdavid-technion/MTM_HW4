#pragma once

#include <Player.h>
#include <../Events/Event.h>

class Character{
    public:
        virtual string printCharacterName() const = 0;
        virtual string reactToPotionsMerchant(Player& player) const = 0;
};

class Responsible: public Character{
    public:
        string printCharacterName() const override;
        string reactToPotionsMerchant(Player& player) const override;
};

class RiskTaking : public Character {
    public:
        string printCharacterName() const override;
        string reactToPotionsMerchant(Player& player) const override;
};