#include <iostream>
#include "SpellCaster.hpp"
#include "Warlock.hpp"
#include "WarlockAbility.hpp"

Warlock::Warlock(const std::string& name, int hp, int mana, int dmg, int mDmg)
    : SpellCaster(name, hp, mana, dmg, mDmg) {

    this->spellCost = manaPointsLimit * 0.05;

    this->action = new WarlockAbility(damage, magicDamage, hitPoints, hitPointsLimit, manaPoints, manaPointsLimit, spellCost);
    this->status = new UnitClassifier(1, 1, 0);

    if ( hp < 1 || dmg < 1 ) {
        throw SpellCasterIsDead();
    }
}

Warlock::~Warlock() {

}

void Warlock::takeDamage(int dmg) {
    SpellCaster::takeDamage(dmg);
}

void Warlock::addManaPoints(int mana) {
    action->addManaPoints(mana);
}

std::ostream& operator<<(std::ostream& out, const Warlock& warlock) {
    out << "Warlock: " << warlock.getName() << "HP:(" << warlock.getHitPointsLimit() << "/" << warlock.getHitPoints() << ")"
    << ", MANA:(" << warlock.getManaPointsLimit() << "/" << warlock.getManaPoints() << ")"
    << ", magic damage: " << warlock.getMagicDamage() << ", damage: " << warlock.getDamage() << std::endl;

    return out;
}