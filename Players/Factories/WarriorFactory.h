#pragma once
#include <Job.h>
#include <Factories/JobFactory.h>
#include <memory>


class WarriorFactory : JobFactory {
    public:
        std::unique_ptr<Job> createJob() const override {
            return std::make_unique<Warrior>();
        }
};