#pragma once
#include "../Job/Job.h"
#include "../Factories/JobFactory.h"
#include "../Job/Warrior.h"
#include <memory>


class WarriorFactory : public JobFactory {
    public:
        ~WarriorFactory() = default;
        std::unique_ptr<Job> createJob() const override {
            return std::make_unique<Warrior>();
        }
};