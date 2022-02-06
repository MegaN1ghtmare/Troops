#include <iostream>
#include "SpellCaster.hpp"
#include "Priest.hpp"
#include "PriestAbility.hpp"

Priest::Priest(const std::string& name, int hp, int mana, int dmg, int mDmg)
    : SpellCaster(name, hp, mana, dmg, mDmg) {

    spellCost = 15;

    this->action = new PriestAbility(damage, magicDamage, hitPoints, hitPointsLimit, manaPoints, manaPointsLimit, spellCost);
    this->status = new UnitClassifier(1, 1, 0);

    if ( hp < 1 || dmg < 1 ) {
        throw SpellCasterIsDead();
    }
}

Priest::~Priest() {

}

void Priest::takeDamage(int dmg) {
    SpellCaster::takeDamage(dmg);
}

void Priest::addManaPoints(int mana) {
    action->addManaPoints(mana);
}

void Priest::counterAttack(Unit& enemy) {
    action->counterAttack(enemy);
}

std::ostream& operator<<(std::ostream& out, const Priest& priest) {
    out << "Priest: " << priest.getName() << "HP:(" << priest.getHitPointsLimit() << "/" << priest.getHitPoints() << ")"
    << ", MANA:(" << priest.getManaPointsLimit() << "/" << priest.getManaPoints() << ")"
    << ", magic damage: " << priest.getMagicDamage() << ", damage: " << priest.getDamage() << std::endl;

    return out;
}
