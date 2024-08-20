#include "Job.h"
#include "Player.h"
#include "../Events/Monster.h"
#include "../Utilities.h"
#include "Warrior.h"
#include <iostream>
#include "PlayerConsts.h"

Warrior::Warrior(int maxHealthPoints) : Job(maxHealthPoints,DEFAULT_COINS) {}

int Warrior::calculateCombatPower(int force, int level) const {
     return (force * WARRIOR_FORCE_FACTOR) + level;
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
     return WARRIOR;
}

string Warrior::reactToSolarEclipse( Player& player) const {
       if(player.applyDarknessConfusion()){
          return getSolarEclipseMessage(player,-1);
        }
        return getSolarEclipseMessage(player,0);
}

std::unique_ptr<Job> Warrior::clone() const {
        return std::make_unique<Warrior>(*this);
}