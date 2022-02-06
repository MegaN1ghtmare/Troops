#include <iostream>
#include "SpellCaster.hpp"
#include "Necromancer.hpp"
// #include "NecromancerAbility.hpp"

Necromancer::Necromancer(const std::string& name, int hp, int mana, int dmg, int mDmg)
    : SpellCaster(name, hp, mana, dmg, mDmg) {

    this->spellCost = 25;

    this->status = new UnitClassifier(1, 1, 1);
    this->observer = new Observer();

    if ( hp < 1 || dmg < 1 ) {
        throw SpellCasterIsDead();
    }
}

Necromancer::~Necromancer() {

}

Observer* Necromancer::getObserver() const {
    return this->observer;
}

void Necromancer::attack(Unit& enemy) {
    SpellCaster::attack(Unit& enemy);
    *this->getObservable()->addObservableToObserverList(enemy, *this);
}

void Necromancer::takeDamage(int dmg) {
    SpellCaster::takeDamage(dmg);
}

void Necromancer::addManaPoints(int mana) {
    action->addManaPoints(mana);
}

std::ostream& operator<<(std::ostream& out, const Necromancer& necromancer) {
    out << "Necromancer: " << necromancer.getName() << "HP:(" << necromancer.getHitPointsLimit() << "/" << necromancer.getHitPoints() << ")"
    << ", MANA:(" << necromancer.getManaPointsLimit() << "/" << necromancer.getManaPoints() << ")"
    << ", magic damage: " << necromancer.getMagicDamage() << ", damage: " << necromancer.getDamage() << std::endl;

    return out;
}