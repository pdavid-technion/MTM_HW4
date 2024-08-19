#include "Character.h"
#include "Player.h"
#include "../Utilities.h"
#include "RiskTaking.h"
#include "PlayerConsts.h"

string RiskTaking::reactToPotionsMerchant( Player& player) const{
    if(player.getHealthPoints() < LOW_HEALTH_THRESHOLD ){
        player.buyPotions(RISK_TAKING_POTION); 
        return getPotionsPurchaseMessage(player,RISK_TAKING_POTION);  
    }
    return getPotionsPurchaseMessage(player,0);
}

string RiskTaking::printCharacterName() const{
    return "RiskTaking";
}

std::unique_ptr<Character> RiskTaking::clone() const {
    return std::make_unique<RiskTaking>(*this);
}