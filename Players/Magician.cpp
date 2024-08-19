#include "Job.h"
#include "Player.h"
#include "../Events/Monster.h"
#include "../Utilities.h"
#include "Magician.h"

Magician::Magician():Job(){}

string Magician::reactToSolarEclipse( Player& player ) const {
     player.applyDarknessMagic();
     return getSolarEclipseMessage(player, 1);
}

string Magician::printJobName() const{
     return "Magician";
}

int Magician::calculateCombatPower(int force, int level) const{
      return force + level;
}
std::string Magician::combatMonster(Player& player, Monster& monster) const{
     if(player.getCombatPower() > monster.getCombatPower()){
          player.winMonster(monster.getLoot());
          return getEncounterWonMessage(player,monster.getLoot());
     }
     else {
          player.loseToMonster(monster.getDamage());
          return getEncounterLostMessage(player, monster.getDamage());
     } 
}

std::unique_ptr<Job> Magician::clone() const {
        return std::make_unique<Magician>(*this);
}