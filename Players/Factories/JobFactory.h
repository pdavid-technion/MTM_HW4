#pragma once

#include <memory>

class Job;

class JobFactory{
    public:
        JobFactory() =  default;
        virtual ~JobFactory() = default;
        virtual std::unique_ptr<Job> createJob() const = 0;

};