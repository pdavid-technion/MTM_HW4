#pragma once

#include "EventFactory.h"
#include "SolarEclipse.h"
#include "Event.h"
#include <memory>

class SolarEclipseFactory: public EventFactory{
    public:
        std::unique_ptr<Event> createEvent() const override{
            return std::make_unique<SolarEclipse>();
        }
};
