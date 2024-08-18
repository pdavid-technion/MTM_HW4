#pragma once

#include <MonsterPack.h>
#include <MonsterFactory.h>
#include <vector>
#include <memory>

class MonsterPackFactory: public MonsterFactory {
    
    public:
        MonsterPackFactory() = default;
        MonsterPackFactory(const std::vector<std::unique_ptr<MonsterFactory>>& factories): factories(factories){}

        std::shared_ptr<Monster> createMonster() const override{
            auto pack = std::make_shared<MonsterPack>();

            for(const auto& factory: factories ){
                pack->addMonster(factory->createMonster());
            }

            return pack;

        }
    
    private:
        std::vector<std::unique_ptr<MonsterFactory>> factories;
};