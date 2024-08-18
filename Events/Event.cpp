#include <Event.h>
#include <../Players/Player.h>

 string MonsterEvent::handleEvent(Player& player){
    string outcome = player.combatMonster(*this->monster);
    this->monster->reactToCombat();
    return outcome;

 }

 string MonsterEvent::getDescription() const{
   return this->monster->getDescription();
 }

 string SolarEclipse::handleEvent(Player& player){
    return player.reactToSolarEclipse();
 }

string SolarEclipse::getDescription() const{
   return "Solar Eclipse";
}


 string PotionsMerchant::handleEvent(Player& player){
   return player.reactToPotionsMerchant();
 }

string PotionsMerchant::getDescription() const{
   return "Potions Merchant";
}