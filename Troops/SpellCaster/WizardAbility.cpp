#include "WizardAbility.hpp"

WizardAbility::WizardAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : SpellCasterAbility(dmg, mDmg, hp, hpLimits, manaPoints, mpLimits, sCost) {
}

WizardAbility::~WizardAbility() {

}

void WizardAbility::magicAttack(SpellCaster& caller, Unit& enemy) {
    enemy.takeMagicDamage(getMagicDamage());
    manaPoints -= caller.getSpellCost();

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }

    caller.addManaPoints(getManaPointsLimit() * 0.05);
}

void WizardAbility::addHitPoints(int hp) {
    ensureIsAlive();

    hp /= 2;

    int maxAddHitPoints = getHitPointsLimit() - getHitPoints();

    if ( hp > maxAddHitPoints ) {
        hitPoints = hitPointsLimit;
        return;
    }

    if ( hp < 0 ) {
        hp *= -1;
    }

    hitPoints += hp;
}
