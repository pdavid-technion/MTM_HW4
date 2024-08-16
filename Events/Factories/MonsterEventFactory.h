#pragma once

#include <EventFactory.h>
#include <Monster.h>
#include <memory>

class MonsterEventFactory: public EventFactory{
    private:
        std::shared_ptr<Monster> monster;

    public:
        MonsterEventFactory(std::shared_ptr<Monster> monster):monster(std::move(monster)){}

        std::shared_ptr<Event> createEvent() const override{
            return std::make_shared<MonsterEvent>(std::move(monster));
        }
};