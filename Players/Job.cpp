#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>
#include <Utilities.h>

Job::Job(int maxHealthPoints, int coins) :maxHealthPoints(maxHealthPoints), coins(coins){}

int Job::calculateCombatPower(int force, int level) const {
        return force + level;
}

string Job::reactToSolarEclipse( Player& player) const {
        if(player.applyDarknessConfusion()){
          return getSolarEclipseMessage(player,-1);
        }
        return getSolarEclipseMessage(player,0);
}


string Job::combatMonster(Player& player, Monster& monster) const{
     if(player.getCombatPower() > monster.getCombatPower()){
            player.winMonster(monster.getLoot());
            return getEncounterWonMessage(player,monster.getLoot());
     }
     else {
          player.loseToMonster(monster.getDamage());
          return getEncounterLostMessage(player, monster.getDamage());
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
