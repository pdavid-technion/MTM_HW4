#include "../Players/Player.h"
#include "MonsterEvent.h"
#include <string> 
#include <iostream>
#include "Snail.h"
#include "Slime.h"
#include "Balrog.h"
 
MonsterEvent::MonsterEvent( std::unique_ptr<Monster> monster) : monster(std::move(monster)) {
    if (!this->monster) {
        throw std::invalid_argument("Monster pointer cannot be null");
    }

    std::cout << "shellyTest "<<this->monster->getDescription() << std::endl;
}

 MonsterEvent::MonsterEvent(Monster* monsterPtr)
        : monster(std::unique_ptr<Monster>(monsterPtr)) {
            std::cout << "shellyTest2 "<<this->monster->getDescription() << std::endl;
}

MonsterEvent::MonsterEvent(string& monsterName){
    std::cout << "monsterName "<<monsterName << std::endl;


         if(monsterName == "Snail"){
           monster = std::make_unique<Snail>();
        }
        else if(!monsterName.compare("Slime")){
            monster = std::make_unique<Slime>();
           
        }
        else if(!monsterName.compare("Balrog")){
            monster = std::make_unique<Balrog>();
        }
}

 string MonsterEvent::handleEvent(Player& player){
    string outcome = player.combatMonster(*this->monster);
    this->monster->reactToCombat();
    return outcome;

 }

 string MonsterEvent::getDescription() const{
        std::cout << " MonsterEvent::getDescription()" << std::endl;
        if(monster){
            std::cout << " whatttttt" << std::endl;
            std::cout << monster->getDamage() << std::endl;
        }
   return this->monster->getDescription();
 }