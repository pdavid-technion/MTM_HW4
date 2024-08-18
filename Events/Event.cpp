#include <Event.h>
#include <../Players/Player.h>

 string Event::getDescription() const{
    return "DAVID implement pls";
 }

 void MonsterEvent::handleEvent(Player& player){
    player.combatMonster(*this->monster);
    this->monster->reactToCombat();

 }

 void SolarEclipse::handleEvent(Player& player){
    player.reactToSolarEclipse();
 }

 void PotionsMerchant::handleEvent(Player& player){
    player.reactToPotionsMerchant();
 }