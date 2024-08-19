#pragma once

#include "Player.h"
#include "../Events/Event.h"

class Character{
    public:
        virtual ~Character() = default;
        virtual string printCharacterName() const = 0;
        virtual string reactToPotionsMerchant(Player& player) const = 0;
        virtual std::unique_ptr<Character> clone() const = 0;
};