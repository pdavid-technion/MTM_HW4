#pragma once

#include "Player.h"
#include "../Events/Event.h"
#include "Character.h"

class RiskTaking: public Character{
    public:
        string printCharacterName() const override;
        string reactToPotionsMerchant(Player& player) const override;
        ~RiskTaking() = default;
        std::unique_ptr<Character> clone() const override;
};