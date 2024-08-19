#pragma once
#include "CharacterFactory.h"
#include "RiskTaking.h"
#include <memory>


class RiskTakingFactory : public CharacterFactory {
    public:
        ~RiskTakingFactory() = default;
        std::unique_ptr<Character> createCharacter() const override {
            return std::make_unique<RiskTaking>();
        }
};