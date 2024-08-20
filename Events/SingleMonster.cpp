#include "SingleMonster.h"

SingleMonster::SingleMonster(int combatPower, int loot, int damage) :
        combatPower(combatPower), loot(loot), damage(damage) {}

int SingleMonster::getCombatPower() const {
    return combatPower;
}

int SingleMonster::getLoot() const {
    return loot;
}

int SingleMonster::getDamage() const {
    return damage;
}

bool SingleMonster::isPack() const {
    return false;
}

void SingleMonster::updateCombatPower(int extraPower) {
    this->combatPower += extraPower;
}
