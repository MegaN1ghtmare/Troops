// #include <iostream>
#include "HealerAbility.hpp"
// #include "SpellCaster.hpp"

HealerAbility::HealerAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : SpellCasterAbility(dmg, mDmg, hp, hpLimits, manaPoints, mpLimits, sCost) {
}

HealerAbility::~HealerAbility() {

}

void HealerAbility::magicAttack(SpellCaster& caller, Unit& enemy) {
    enemy.takeMagicDamage(getMagicDamage() * 0.5);

    manaPoints -= caller.getSpellCost();

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }

    caller.addManaPoints(getManaPointsLimit() * 0.07);
}
