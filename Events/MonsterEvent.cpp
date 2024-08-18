#include "Event.h"
#include "../Players/Player.h"
#include "MonsterEvent.h"
#include <string> 
 
MonsterEvent::MonsterEvent(Monster* monster) : monster(monster) {
    if (!monster) {
        throw std::invalid_argument("Monster pointer cannot be null");
    }
} 

 string MonsterEvent::handleEvent(Player& player){
    string outcome = player.combatMonster(*this->monster);
    this->monster->reactToCombat();
    return outcome;

 }

 string MonsterEvent::getDescription() const{
   return this->monster->getDescription();
 }