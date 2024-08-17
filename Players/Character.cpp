#include <Character.h>
#include <Player.h>
//TODO - SHELLY - consts
void Responsible::reactToPotionsMerchant( Player& player) const{
    int maxPotionsAffordable = player.getCoins() / 5;
    int maxPotionsViable = ( player.getMaxHealthPoints() - player.getHealthPoints() ) / 10;
    int potionsToBuy = std::min(maxPotionsAffordable, maxPotionsViable);
    
    player.buyPotions(potionsToBuy);
}
void RiskTaking::reactToPotionsMerchant( Player& player) const{
    if(player.getHealthPoints() < 50 ){
        player.buyPotions(1);
    }
}