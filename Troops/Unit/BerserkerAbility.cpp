#include <iostream>
#include "BerserkerAbility.hpp"
#include "Unit.hpp"

BerserkerAbility::BerserkerAbility(int& dmg, int& hp, int& hpLimits)
    : Ability(dmg, hp, hpLimits) {
}

BerserkerAbility::~BerserkerAbility() {

}

void BerserkerAbility::takeMagicDamage(int dmg) {
    ensureIsAlive();
    std::cout << "Berserker has immunitate for magic damage!" << std::endl;
}

void BerserkerAbility::counterAttack(Unit& enemy) {
    int counterAttackDmg = getDamage() / 2;

    enemy.takeDamage(counterAttackDmg);
}
