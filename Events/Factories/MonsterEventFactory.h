#pragma once

#include "EventFactory.h"
#include "../Monster.h"
#include "../MonsterEvent.h"
#include <memory>

class MonsterEventFactory: public EventFactory{
    private:
        std::unique_ptr<Monster> monster;

    public:
        MonsterEventFactory(std::unique_ptr<Monster> monster) : monster(std::move(monster)) {}

        std::unique_ptr<Event> createEvent() const override{
            return std::make_unique<MonsterEvent>(monster.get());
        }
};