#pragma once

#include "../Players/Player.h"
#include "Monster.h"
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

    virtual ~Event() = default;
};