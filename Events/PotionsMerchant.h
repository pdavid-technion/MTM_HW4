#pragma once

#include "../Players/Player.h"
#include "Monster.h"
#include <vector>
#include "Event.h"

class PotionsMerchant: public Event {
        
    public:
        string handleEvent(Player& player) override;  
        string getDescription() const override; 
        virtual ~PotionsMerchant() = default;
};