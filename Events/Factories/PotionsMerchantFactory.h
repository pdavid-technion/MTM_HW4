#pragma once

#include <EventFactory.h>
#include <Event.h>
#include <memory>

class PotionsMerchantFactory: public EventFactory{
    public:
        std::shared_ptr<Event> createEvent() const override{
            return std::make_shared<PotionsMerchant>();
        }
};
