#include "Event.h"
#include "../Players/Player.h"
#include "PotionsMerchant.h"
#include <string> 
#include <iostream>
#include "../Players/PlayerConsts.h"

string PotionsMerchant::handleEvent(Player& player){
   return player.reactToPotionsMerchant();
}

string PotionsMerchant::getDescription() const{
   return POTIONS_MERCHANT;
}