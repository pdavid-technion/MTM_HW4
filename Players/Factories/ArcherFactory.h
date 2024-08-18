#pragma once
#include "../Job/Job.h"
#include "JobFactory.h"
#include "../Job/Archer.h"
#include <memory>


class ArcherFactory : public JobFactory {
    public:
    ~ArcherFactory() = default;
    std::unique_ptr<Job> createJob() const override {
        return std::make_unique<Archer>();
    }
};