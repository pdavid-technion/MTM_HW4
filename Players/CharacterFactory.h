#pragma once

#include <memory>

class Character;

class CharacterFactory{
    public:
        virtual ~CharacterFactory() = default;
        virtual std::unique_ptr<Character> createCharacter() const = 0;

};