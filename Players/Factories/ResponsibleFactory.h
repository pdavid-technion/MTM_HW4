#pragma once
#include "../Character/Character.h"
#include "CharacterFactory.h"
#include <memory>


class ResponsibleFactory : public CharacterFactory {
    public:
        ~ResponsibleFactory() = default;
        std::unique_ptr<Character> createCharacter() const override {
            return std::make_unique<Responsible>();
        }
};