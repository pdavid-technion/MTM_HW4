#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>
#include <Utilities.h>

//TODO - SHELLY - consts

int Warrior::calculateCombatPower(int force, int level) const {
     return force * 2 + level;
}

string Warrior::combatMonster(Player& player, Monster& monster) const{
     if(player.getCombatPower() > monster.getCombatPower()){
          player.winMonster(monster.getLoot());
          player.closeEncounter();
          return getEncounterWonMessage(player,monster.getLoot());
     }
     else {
          player.loseToMonster(monster.getDamage());
          return getEncounterLostMessage(player, monster.getDamage());
     }

}

string Warrior::printJobName() const{
     return "Warrior";
}
