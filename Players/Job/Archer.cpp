#include "Job.h"
#include "../Player.h"
#include "../../Events/Monster.h"
#include "Archer.h"

//TODO - SHELLY - consts

Archer::Archer(int coins) : Job(100, coins) {}

string Archer::printJobName() const{
    return "Archer";
}

string Archer::reactToSolarEclipse( Player& player) const {
    player.applyDarknessConfusion();
    return getSolarEclipseMessage(player,-1);
}

int Archer::calculateCombatPower(int force, int level) const {
   return force + level;
}

std::string Archer::combatMonster(Player& player, Monster& monster) const {
    if(player.getCombatPower() > monster.getCombatPower()){
            player.winMonster(monster.getLoot());
            return getEncounterWonMessage(player,monster.getLoot());
     }
     else {
          player.loseToMonster(monster.getDamage());
          return getEncounterLostMessage(player, monster.getDamage());
     } 
}