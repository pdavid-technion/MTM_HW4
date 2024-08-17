#include <Character.h>
#include <Player.h>
//TODO - SHELLY - consts

void RiskTaking::reactToPotionsMerchant( Player& player) const{
    if(player.getHealthPoints() < 50 ){
        player.buyPotions(1);
    }
}

string RiskTaking::printCharacterName() const{
    return "RiskTaking";
}