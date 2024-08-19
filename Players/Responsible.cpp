#include "Character.h"
#include "Player.h"
#include "../Utilities.h"
#include "Responsible.h"
#include "GameConsts.h"

string Responsible::reactToPotionsMerchant( Player& player) const{
    int maxPotionsAffordable = player.getCoins() / POTION_COST;
    int maxPotionsViable = ( player.getMaxHealthPoints() - 
        player.getHealthPoints() ) / POTION_HEALTHPOINTS;
    int potionsToBuy = std::min(maxPotionsAffordable, maxPotionsViable);
    
    player.buyPotions(potionsToBuy);
    return getPotionsPurchaseMessage(player,potionsToBuy);
}

string Responsible::printCharacterName() const{
    return "Responsible";
}

std::unique_ptr<Character> Responsible::clone() const {
    return std::make_unique<Responsible>(*this);
}