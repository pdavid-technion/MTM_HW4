#include "../Players/Player.h"
#include "MonsterEvent.h"
#include <string>
#include <iostream>
#include "Snail.h"
#include "Slime.h"
#include "Balrog.h"

MonsterEvent::MonsterEvent(std::unique_ptr<Monster> newMonster) : monster(std::move(newMonster)){
    if (!this->monster){
        throw std::invalid_argument("Monster pointer cannot be null");
    }
}
MonsterEvent::MonsterEvent(std::unique_ptr<MonsterPack> newMonsterPack){
     this->monster = std::move(newMonsterPack);
}
MonsterEvent::MonsterEvent(Monster *monsterPtr)
    : monster(std::unique_ptr<Monster>(monsterPtr)){
}

MonsterEvent::MonsterEvent(string &monsterName){

    if (monsterName == SNAIL){
        monster = std::make_unique<Snail>();
    }
    else if (!monsterName.compare(SLIME)){
        monster = std::make_unique<Slime>();
    }
    else if (!monsterName.compare(BALROG)){
        monster = std::make_unique<Balrog>();
    }
}

string MonsterEvent::handleEvent(Player &player){
    string outcome = player.combatMonster(*this->monster);
    this->monster->reactToCombat();
    return outcome;
}

string MonsterEvent::getDescription() const{
    return this->monster->getDescription();
}