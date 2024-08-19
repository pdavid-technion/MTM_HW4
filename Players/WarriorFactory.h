#pragma once
#include "Job.h"
#include "JobFactory.h"
#include "Warrior.h"
#include <memory>


class WarriorFactory : public JobFactory {
    public:
        ~WarriorFactory() = default;
        std::unique_ptr<Job> createJob() const override {
            return std::make_unique<Warrior>();
        }
};