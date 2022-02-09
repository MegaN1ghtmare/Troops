#include "SpellCasterAbility.hpp"

SpellCasterAbility::SpellCasterAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    :   Ability(dmg, hp, hpLimits),
        magicDamage(mDmg), manaPoints(manaPoints),
        manaPointsLimit(mpLimits), spellCost(sCost)
    {
}

SpellCasterAbility::~SpellCasterAbility() {

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

void SpellCasterAbility::magicAttack(SpellCaster& caller, Unit& enemy) {
    enemy.takeMagicDamage(getMagicDamage());

    manaPoints -= caller.getSpellCost();

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }

    caller.addManaPoints(getManaPointsLimit() * 0.03);
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

std::string SpellCasterAbility::getDemonMap() const {
    std::string out = "No Demons aviliable";

    return out;
}
