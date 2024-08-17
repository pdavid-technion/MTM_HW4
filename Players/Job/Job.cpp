#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>

Job::Job(int maxHealthPoints, int coins) :maxHealthPoints(maxHealthPoints), coins(coins){}

int Job::calculateCombatPower(int force, int level) const {
        return force + level;
}

void Job::reactToSolarEclipse( Player& player) const {
        player.applyDarknessConfusion();
    }


void Job::combatMonster(Player& player, Monster& monster) const{
       if(player.getCombatPower() > monster.getCombatPower()){
            player.winMonster(monster.getLoot());
     }
     else {
          player.loseToMonster(monster.getDamage());
     } 
}

int Job::getMaxHealthPoints(){
     return this->maxHealthPoints;
}

int Job::getCoins(){
     return this->coins;
}
void Job::setCoins(int newCoins){
     this->coins = newCoins;
}
