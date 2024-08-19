#include "Event.h"
#include "../Players/Player.h"
#include "PotionsMerchant.h"
#include <string> 
#include <iostream>

string PotionsMerchant::handleEvent(Player& player){
   return player.reactToPotionsMerchant();
}

string PotionsMerchant::getDescription() const{
std::cout << " PotionsMerchant::getDescription()" << std::endl;
   return "Potions Merchant";
}