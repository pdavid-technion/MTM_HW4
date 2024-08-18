#pragma once
#include <Job.h>
#include <JobFactory.h>
#include <memory>


class ArcherFactory : public JobFactory {
    public:
        std::unique_ptr<Job> createJob() const override {
            return std::make_unique<Archer>();
        }
};