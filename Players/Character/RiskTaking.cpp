#include <Character.h>
#include <Player.h>
#include <Utilities.h>
//TODO - SHELLY - consts

string RiskTaking::reactToPotionsMerchant( Player& player) const{
    if(player.getHealthPoints() < 50 ){
        player.buyPotions(1); 
        return getPotionsPurchaseMessage(player,1);  
    }
    return getPotionsPurchaseMessage(player,0);
}

string RiskTaking::printCharacterName() const{
    return "RiskTaking";
}