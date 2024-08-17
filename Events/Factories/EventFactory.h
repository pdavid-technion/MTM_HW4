#pragma once

#include <memory>
#include <Event.h>

class Event;

class EventFactory{
    public:
    virtual ~EventFactory() = default;
    virtual std::shared_ptr<Event> createEvent() const = 0;
};