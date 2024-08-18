#pragma once
#include "../Character/Character.h"
#include "CharacterFactory.h"
#include <memory>


class RiskTakingFactory : public CharacterFactory {
    public:
        ~RiskTakingFactory() = default;
        std::unique_ptr<Character> createCharacter() const override {
            return std::make_unique<RiskTaking>();
        }
};