#include <iostream>
#include "HealerAbility.hpp"
#include "SpellCaster.hpp"

HealerAbility::HealerAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : SpellCasterAbility(dmg, mDmg, hp, hpLimits, manaPoints, mpLimits, sCost) {
}

HealerAbility::~HealerAbility() {

}

void HealerAbility::attack(Unit& caller, Unit& enemy) {
    if ( caller.getManaPoints() >= caller.getSpellCost() ) {
        enemy.takeMagicDamage(getMagicDamage() * 0.5);
        manaPoints -= caller.getSpellCost();
    } else {
        enemy.takeDamage(getDamage());
    }

    caller.addManaPoints(getManaPointsLimit() * 0.07);

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }
}

void HealerAbility::addManaPoints(int mana) {
    SpellCasterAbility::addManaPoints(mana);
}
