#pragma once
#include "../Job/Job.h"
#include "JobFactory.h"
#include <memory>
#include "../Job/Magician.h"


class MagicianFactory : public JobFactory {
    public:
        ~MagicianFactory() = default;
        std::unique_ptr<Job> createJob() const override {
            return std::make_unique<Magician>();
        }
};