#include "SpellCaster.hpp"

SpellCaster::SpellCaster(const std::string& name, int hp, int mana, int dmg, int mDmg)
    :   Unit(name, hp, dmg),
        manaPoints(mana), manaPointsLimit(mana),
        magicDamage(mDmg) {

    spellCost = manaPointsLimit / 10;

    this->action = new SpellCasterAbility(damage, magicDamage, hitPoints, hitPointsLimit, manaPoints, manaPointsLimit, spellCost);
    this->status = new UnitClassifier(1, 1, 0);
}

SpellCaster::~SpellCaster() {

}

int SpellCaster::getMagicDamage() const {
    return this->magicDamage;
}

int SpellCaster::getManaPoints() const {
    return this->manaPoints;
}

int SpellCaster::getManaPointsLimit() const {
    return this->manaPointsLimit;
}

int SpellCaster::getSpellCost() const {
    return this->spellCost;
}

void SpellCaster::takeDamage(int dmg) {
    action->takeDamage(dmg);
    checkUnitAlives();
}

void SpellCaster::attack(Unit& enemy) {
    if ( getManaPoints() >= getSpellCost() ) {
        action->magicAttack(*this, enemy);
    } else {
        action->attack(*this, enemy);
    }
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster) {
    out << "SpellCaster: " << spellCaster.getName() << "HP:(" << spellCaster.getHitPointsLimit() << "/" << spellCaster.getHitPoints() << ")"
    << ", MANA:(" << spellCaster.getManaPointsLimit() << "/" << spellCaster.getManaPoints() << ")"
    << ", magic damage: " << spellCaster.getMagicDamage() << ", damage: " << spellCaster.getDamage() << std::endl;

    return out;
}
