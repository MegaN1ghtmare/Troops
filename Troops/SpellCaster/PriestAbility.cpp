#include <iostream>
#include "PriestAbility.hpp"
#include "SpellCaster.hpp"

#define UNDEADDMGMLTP 2

PriestAbility::PriestAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : SpellCasterAbility(dmg, mDmg, hp, hpLimits, manaPoints, mpLimits, sCost) {
}

PriestAbility::~PriestAbility() {

}

void PriestAbility::attack(Unit& caller, Unit& enemy) {
    int undeadDmgMuliplier = 1;

    if (enemy.getIfUnitUndead()) {
        undeadDmgMuliplier *= UNDEADDMGMLTP;
    }

    if ( caller.getManaPoints() >= caller.getSpellCost() ) {
        enemy.takeMagicDamage(getMagicDamage() * 0.5 * undeadDmgMuliplier);
        manaPoints -= caller.getSpellCost();
    } else {
        enemy.takeDamage(getDamage() * undeadDmgMuliplier);
    }

    caller.addManaPoints(getManaPointsLimit() * 0.05);

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }
}

void PriestAbility::counterAttack(Unit& enemy) {
    int counterAttackDmg = getDamage() / 2;

    if (enemy.getIfUnitUndead()) {
        counterAttackDmg *= UNDEADDMGMLTP;
    }

    enemy.takeDamage(counterAttackDmg);
}

void PriestAbility::addManaPoints(int mana) {
    SpellCasterAbility::addManaPoints(mana);
}
