#pragma once

#include "../Players/Player.h"
#include "Monster.h"
#include <vector>
#include "Event.h"

class SolarEclipse: public Event {
        
    public:
        string handleEvent(Player& player) override;
        string getDescription() const override;
        virtual ~SolarEclipse() = default;
};
