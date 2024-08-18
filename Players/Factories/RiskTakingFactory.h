#pragma once
#include <Character.h>
#include <CharacterFactory.h>
#include <memory>


class RiskTakingFactory : public CharacterFactory {
    public:
        std::unique_ptr<Character> createCharacter() const override {
            return std::make_unique<RiskTaking>();
        }
};