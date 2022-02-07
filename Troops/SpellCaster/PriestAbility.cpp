#include "PriestAbility.hpp"

#define UNDEADDMGMLTP 2

PriestAbility::PriestAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : SpellCasterAbility(dmg, mDmg, hp, hpLimits, manaPoints, mpLimits, sCost) {
}

PriestAbility::~PriestAbility() {

}

void PriestAbility::magicAttack(SpellCaster& caller, Unit& enemy) {
    int undeadDmgMuliplier = 1;

    if (enemy.getIfUnitUndead()) {
        undeadDmgMuliplier *= UNDEADDMGMLTP;
    }

    enemy.takeMagicDamage(getMagicDamage() * 0.5 * undeadDmgMuliplier);
    manaPoints -= caller.getSpellCost();

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }

    caller.addManaPoints(getManaPointsLimit() * 0.05);
}

void PriestAbility::counterAttack(Unit& enemy) {
    int counterAttackDmg = getDamage() / 2;

    if (enemy.getIfUnitUndead()) {
        counterAttackDmg *= UNDEADDMGMLTP;
    }

    enemy.takeDamage(counterAttackDmg);
}
