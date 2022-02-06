#include <iostream>
#include "VampireAbility.hpp"
#include "Unit.hpp"

VampireAbility::VampireAbility(int& dmg, int& hp, int& hpLimits)
    : Ability(dmg, hp, hpLimits) {
}

VampireAbility::~VampireAbility() {

}

void VampireAbility::attack(Unit& caller, Unit& enemy) {
    int enemyCurrentHP = enemy.getHitPoints();
    int vampireDmg = getDamage();

    if ( enemyCurrentHP < vampireDmg ) {
        caller.addHitPoints(enemyCurrentHP / 2);
        enemy.takeDamage(vampireDmg);
    } else {
        caller.addHitPoints(vampireDmg / 2);
        enemy.takeDamage(vampireDmg);
    }

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }
}

void VampireAbility::counterAttack(Unit& enemy) {
    int counterAttackDmg = getDamage() / 2;

    if ( counterAttackDmg > enemy.getHitPoints() ) {
        enemy.takeDamage(counterAttackDmg);
        this->addHitPoints(enemy.getHitPoints() / 2);

        return;
    }

    enemy.takeDamage(counterAttackDmg);
    this->addHitPoints(counterAttackDmg / 2);
}
