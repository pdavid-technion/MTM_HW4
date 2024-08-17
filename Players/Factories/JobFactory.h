#pragma once

#include <memory>

class Job;

class JobFactory{
    public:
        virtual ~JobFactory() = default;
        virtual std::unique_ptr<Job> createJob() const = 0;

};