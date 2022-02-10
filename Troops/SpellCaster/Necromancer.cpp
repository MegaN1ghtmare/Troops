#include "Necromancer.hpp"

Necromancer::Necromancer(const std::string& name, int hp, int mana, int dmg, int mDmg)
    : SpellCaster(name, hp, mana, dmg, mDmg) {

    this->spellCost = 25;
    this->action = new SpellCasterAbility(damage, magicDamage, hitPoints, hitPointsLimit, manaPoints, manaPointsLimit, spellCost);
    this->status = new UnitClassifier(1, 1, 1);
}

Necromancer::~Necromancer() {

}

void Necromancer::attack(Unit& enemy) {
    if ( getManaPoints() >= getSpellCost() ) {
        action->magicAttack(*this, enemy);
    } else {
        action->attack(*this, enemy);
    }
    (*this).getObservable()->addObservableToObserverList(enemy, *this);
}

void Necromancer::addManaPoints(int mana) {
    action->addManaPoints(mana);
}

std::ostream& operator<<(std::ostream& out, const Necromancer& necromancer) {
    out << "Necromancer: " << necromancer.getName() << ", HP:(" << necromancer.getHitPointsLimit() << "/" << necromancer.getHitPoints() << ")"
    << ", MANA:(" << necromancer.getManaPointsLimit() << "/" << necromancer.getManaPoints() << ")"
    << ", magic damage: " << necromancer.getMagicDamage() << ", damage: " << necromancer.getDamage() << std::endl << necromancer.getList();

    return out;
}
