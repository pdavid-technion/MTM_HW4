#include <Event.h>
#include <../Players/Player.h>

 string Event::getDescription() const{
    return "DAVID implement pls";
 }

 string MonsterEvent::handleEvent(Player& player){
    string outcome = player.combatMonster(*this->monster);
    this->monster->reactToCombat();
    return outcome;

 }

 string SolarEclipse::handleEvent(Player& player){
    return player.reactToSolarEclipse();
 }

 string PotionsMerchant::handleEvent(Player& player){
   return player.reactToPotionsMerchant();
 }