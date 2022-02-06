#include <iostream>
#include "WizardAbility.hpp"
#include "SpellCaster.hpp"

WizardAbility::WizardAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : SpellCasterAbility(dmg, mDmg, hp, hpLimits, manaPoints, mpLimits, sCost) {
}

WizardAbility::~WizardAbility() {

}

void WizardAbility::attack(Unit& caller, Unit& enemy) {
    if ( caller.getManaPoints() >= caller.getSpellCost() ) {
        enemy.takeMagicDamage(getMagicDamage() * 1.1);
        manaPoints -= caller.getSpellCost();
    } else {
        enemy.takeDamage(getDamage());
    }

    caller.addManaPoints(getManaPointsLimit() * 0.05);

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }
}

void WizardAbility::addManaPoints(int mana) {
    SpellCasterAbility::addManaPoints(mana);
}
