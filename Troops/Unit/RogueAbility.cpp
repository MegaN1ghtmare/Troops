#include "RogueAbility.hpp"

RogueAbility::RogueAbility(int& dmg, int& hp, int& hpLimits)
    : Ability(dmg, hp, hpLimits) {
}

RogueAbility::~RogueAbility() {

}

void RogueAbility::attack(Unit& caller, Unit& enemy) {
    enemy.takeDamage(getDamage());
}
