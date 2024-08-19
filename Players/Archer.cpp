#include "Job.h"
#include "Player.h"
#include "../Events/Monster.h"
#include "Archer.h"
#include "GameConsts.h"

Archer::Archer(int coins) : Job(DEFAULT_HEALTH_POINTS, coins) {}

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

std::unique_ptr<Job> Archer::clone() const {
        return std::make_unique<Archer>(*this);
}