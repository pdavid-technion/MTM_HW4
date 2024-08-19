#include "Event.h"
#include "../Players/Player.h"
#include "PotionsMerchant.h"
#include <string> 

string PotionsMerchant::handleEvent(Player& player){
   return player.reactToPotionsMerchant();
}

string PotionsMerchant::getDescription() const{
   return "Potions Merchant";
}