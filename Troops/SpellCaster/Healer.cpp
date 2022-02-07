#include "Healer.hpp"

Healer::Healer(const std::string& name, int hp, int mana, int dmg, int mDmg)
    : SpellCaster(name, hp, mana, dmg, mDmg) {

    spellCost = 12;

    this->action = new HealerAbility(damage, magicDamage, hitPoints, hitPointsLimit, manaPoints, manaPointsLimit, spellCost);
    this->status = new UnitClassifier(1, 1, 0);

    if ( hp < 1 || dmg < 1 ) {
        throw SpellCasterIsDead();
    }
}

Healer::~Healer() {

}

void Healer::addManaPoints(int mana) {
    action->addManaPoints(mana);
}

std::ostream& operator<<(std::ostream& out, const Healer& healer) {
    out << "Healer: " << healer.getName() << "HP:(" << healer.getHitPointsLimit() << "/" << healer.getHitPoints() << ")"
    << ", MANA:(" << healer.getManaPointsLimit() << "/" << healer.getManaPoints() << ")"
    << ", magic damage: " << healer.getMagicDamage() << ", damage: " << healer.getDamage() << std::endl;

    return out;
}
