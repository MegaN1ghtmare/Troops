#include <iostream>
// #include "../Unit/Unit.hpp"
#include "../Unit/Ability.hpp"
#include "SpellCasterAbility.hpp"
#include "SpellCaster.hpp"

void SpellCasterAbility::ensureIsAlive() {
   if ( this->hitPoints == 0 ) {
       throw SpellCasterIsDead();
   }
}

SpellCasterAbility::SpellCasterAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : Ability(dmg, hp, hpLimits),
    magicDamage(mDmg), damage(dmg), hitPoints(hp), hitPointsLimit(hpLimits),
    manaPoints(manaPoints), manaPointsLimit(mpLimits), spellCost(sCost) {
}

SpellCasterAbility::~SpellCasterAbility() {

}

int& SpellCasterAbility::getDamage() const {
    return damage;
}

int& SpellCasterAbility::getHitPoints() const {
    return hitPoints;
}

int& SpellCasterAbility::getHitPointsLimit() const {
    return hitPointsLimit;
}

int& SpellCasterAbility::getMagicDamage() const {
    return magicDamage;
}

int& SpellCasterAbility::getManaPoints() const {
    return manaPoints;
}

int& SpellCasterAbility::getManaPointsLimit() const {
    return manaPointsLimit;
}

int& SpellCasterAbility::getSpellCost() const {
    return spellCost;
}

void SpellCasterAbility::addHitPoints(int hp) {
    ensureIsAlive();

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

void SpellCasterAbility::addManaPoints(int mana) {
    ensureIsAlive();

    int maxAddManaPoints = getManaPointsLimit() - getManaPoints();

    if ( mana > maxAddManaPoints ) {
        manaPoints = manaPointsLimit;
        return;
    }

    manaPoints += mana;
}

void SpellCasterAbility::takeDamage(int dmg) {
    ensureIsAlive();

    if ( dmg >= getHitPoints() ) {
        hitPoints = 0;

        return;
    }

    hitPoints -= dmg;
}

void SpellCasterAbility::takeMagicDamage(int dmg) {
    ensureIsAlive();

    if ( dmg >= getHitPoints() ) {
        hitPoints = 0;

        return;
    }

    hitPoints -= dmg;
}

void SpellCasterAbility::attack(Unit& caller, Unit& enemy) {
    if ( caller.getManaPoints() >= caller.getSpellCost() ) {
        enemy.takeMagicDamage(getMagicDamage());
        manaPoints -= caller.getSpellCost();
    } else {
        enemy.takeDamage(getDamage());
    }

    caller.addManaPoints(getManaPointsLimit() * 0.03);

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }
}

void SpellCasterAbility::counterAttack(Unit& enemy) {
    int counterAttackDmg = getDamage() / 2;

    enemy.takeDamage(counterAttackDmg);
}
