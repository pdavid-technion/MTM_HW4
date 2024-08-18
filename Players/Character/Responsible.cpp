#include "Character.h"
#include "../Player.h"
#include "../../Utilities.h"
//TODO - SHELLY - consts
string Responsible::reactToPotionsMerchant( Player& player) const{
    int maxPotionsAffordable = player.getCoins() / 5;
    int maxPotionsViable = ( player.getMaxHealthPoints() - player.getHealthPoints() ) / 10;
    int potionsToBuy = std::min(maxPotionsAffordable, maxPotionsViable);
    
    player.buyPotions(potionsToBuy);
    return getPotionsPurchaseMessage(player,potionsToBuy);
}

string Responsible::printCharacterName() const{
    return "Responsible";
}