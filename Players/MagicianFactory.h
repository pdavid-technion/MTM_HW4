#pragma once
#include "Job.h"
#include "JobFactory.h"
#include <memory>
#include "Magician.h"


class MagicianFactory : public JobFactory {
    public:
        ~MagicianFactory() = default;
        std::unique_ptr<Job> createJob() const override {
            return std::make_unique<Magician>();
        }
};