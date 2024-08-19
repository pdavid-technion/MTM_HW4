#pragma once

#include "EventFactory.h"
#include "Monster.h"
#include "MonsterEvent.h"
#include <memory>
#include "Events/SolarEclipse.h"
#include "Events/PotionsMerchant.h"

class MonsterEventFactory //: public EventFactory
{
private:
    // std::unique_ptr<Monster> monster;

public:
    // MonsterEventFactory(std::unique_ptr<Monster> monster) : monster(std::move(monster)) {}
    MonsterEventFactory() = default;
    // std::unique_ptr<Event> createEvent() const override
    // {
    //     std::cout << "gadddd" << monster->getCombatPower() << std::endl;
    //     auto x = monster.get();
    //     std::cout << "yasss????" << monster->getCombatPower() << std::endl;
    //     std::cout << "x->getDamage() " << x->getDamage() << std::endl;
    //     auto a = std::make_unique<MonsterEvent>(monster.get());
    //     std::cout << "olaaaaa " << std::endl;

    //     std::cout << "a->getDescription() " << a->getDescription() << std::endl;

    //     return a;
    // }

     std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \n\r\t");
    size_t last = str.find_last_not_of(" \n\r\t");
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

    std::string extractNextWord(std::string &line)
    {
        // size_t pos = line.find(' ');
        // std::string word = (pos == std::string::npos) ? line : line.substr(0, pos);
        // line = (pos == std::string::npos) ? "" : line.substr(pos + 1);
        // return word;

        line = trim(line);

        // Find the position of the first space or newline
        size_t pos = line.find_first_of(" \n");

        // Extract the word
        std::string word = (pos == std::string::npos) ? line : line.substr(0, pos);

        // Update the line to remove the extracted word
        line = (pos == std::string::npos) ? "" : line.substr(pos + 1);

        // Trim the line again for the next extraction
        line = trim(line);

        return word;
    }

    std::unique_ptr<Monster> createMonsterFromType(const std::string &type)
    {
        if (!type.compare("Snail"))
        {
            return SnailFactory{}.createMonster();
        }
        else if (!type.compare("Balrog"))
        {
            return BalrogFactory{}.createMonster();
        }
        else if (!type.compare("Slime"))
        {
            return SlimeFactory{}.createMonster();
        }
        return nullptr;
    }

    std::unique_ptr<MonsterPack> parseMonsterPack(std::string &line)
    {
        int packSize = std::stoi(extractNextWord(line));
        auto pack = std::make_unique<MonsterPack>();
        for (int i = 0; i < packSize; ++i)
        {
            std::string word = extractNextWord(line);
            if (!word.compare("Pack"))
            {
                auto subPack = parseMonsterPack(line);
                pack->addMonster(std::move(subPack));
            }
            else
            {
                auto monster = createMonsterFromType(word);
                pack->addMonster(std::move(monster));
            }
        }

        return pack;
    }

    std::unique_ptr<Event> createShulaEvent(std::string &line)
    {
        std::string firstWord = extractNextWord(line);

        // if (!firstWord.compare("Pack"))
        // {
        //     std::cout << "pack " << std::endl;
        //     auto pack = parseMonsterPack(line);
        //     //std::unique_ptr<Monster> monsterPackPtr = std::move(pack);
        //     //auto a = std::make_unique<MonsterEvent>(pack);
        //     //return a;
        //     // eventsList.push_back(std::move(factory.createEvent()));
        // }
        //else 
        if (!firstWord.compare("SolarEclipse"))
        {

            // SolarEclipseFactory factory;
            auto b = std::make_unique<SolarEclipse>();
            return b;

            // eventsList.push_back(std::move(factory.createEvent()));
        }
        else if (!firstWord.compare("PotionsMerchant"))
        {

            // PotionsMerchantFactory factory;
            auto c = std::make_unique<PotionsMerchant>();
            return c;
            // eventsList.push_back(std::move(factory.createEvent()));
        }

        else if(firstWord == "Snail"){
            auto d = std::make_unique<MonsterEvent>(firstWord);
            return d;
        }
        else if(!firstWord.compare("Slime")){
            auto e = std::make_unique<MonsterEvent>(firstWord);
            return e;
        }
        else if(!firstWord.compare("Balrog")){
            auto f = std::make_unique<MonsterEvent>(firstWord);
            return f;
        }
        else if (firstWord.compare("Pack"))
        {
            string mm = "Balrog";
            auto f = std::make_unique<MonsterEvent>(mm);
            return f;
        } else{
            throw std::invalid_argument("Invalid Event File");
        }
    }

    void shula()
    {
        //std::cout << "monster->getCombatPower() from MonsterFactory" << monster->getCombatPower() << std::endl;
    }
};