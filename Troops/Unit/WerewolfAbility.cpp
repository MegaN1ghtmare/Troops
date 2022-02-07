#include "WerewolfAbility.hpp"

#define VULNERABILITYTOMAGICMTPL 3

WerewolfAbility::WerewolfAbility(int& dmg, int& hp, int& hpLimits)
    : Ability(dmg, hp, hpLimits) {
}

WerewolfAbility::~WerewolfAbility() {

}

void WerewolfAbility::takeMagicDamage(int dmg) {
    ensureIsAlive();

    dmg *= VULNERABILITYTOMAGICMTPL;

    if ( dmg >= getHitPoints() ) {
        hitPoints = 0;

        return;
    }

    hitPoints -= dmg;
}

void WerewolfAbility::takeDamage(int dmg) {
    ensureIsAlive();

    if ( dmg >= getHitPoints() ) {
        hitPoints = 0;

        return;
    }

    hitPoints -= dmg;
}
