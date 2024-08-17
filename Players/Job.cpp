#include <Job.h>
#include <Player.h>
#include <../Events/Monster.h>

int Warrior::calculateCombatPower(int force, int level) const {
     return force * 2 + level;
}

void Warrior::combatMonster(Player& player, Monster& monster) const{
     if(player.getCombatPower() > monster.getCombatPower()){
          player.winMonster(monster.getLoot());
          player.closeEncounter();
     }
     else {
          player.loseToMonster(monster.getDamage());
     }

}

void Archer::combatMonster(Player& player, Monster& monster) const{
       if(player.getCombatPower() > monster.getCombatPower()){
            player.winMonster(monster.getLoot());
     }
     else {
          player.loseToMonster(monster.getDamage());
     } 
}

void Magician::combatMonster(Player& player, Monster& monster) const{
        if(player.getCombatPower() > monster.getCombatPower()){
            player.winMonster(monster.getLoot());
     }
     else {
          player.loseToMonster(monster.getDamage());
     }
}