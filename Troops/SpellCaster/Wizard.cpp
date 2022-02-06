#include <iostream>
#include "SpellCaster.hpp"
#include "Wizard.hpp"
#include "WizardAbility.hpp"

Wizard::Wizard(const std::string& name, int hp, int mana, int dmg, int mDmg)
    : SpellCaster(name, hp, mana, dmg, mDmg) {

    this->spellCost = 20;

    this->action = new WizardAbility(damage, magicDamage, hitPoints, hitPointsLimit, manaPoints, manaPointsLimit, spellCost);
    this->status = new UnitClassifier(1, 1, 0);

    if ( hp < 1 || dmg < 1 ) {
        throw SpellCasterIsDead();
    }
}

Wizard::~Wizard() {

}

void Wizard::takeDamage(int dmg) {
    SpellCaster::takeDamage(dmg);
}

void Wizard::addManaPoints(int mana) {
    action->addManaPoints(mana);
}

std::ostream& operator<<(std::ostream& out, const Wizard& wizard) {
    out << "Wizard: " << wizard.getName() << "HP:(" << wizard.getHitPointsLimit() << "/" << wizard.getHitPoints() << ")"
    << ", MANA:(" << wizard.getManaPointsLimit() << "/" << wizard.getManaPoints() << ")"
    << ", magic damage: " << wizard.getMagicDamage() << ", damage: " << wizard.getDamage() << std::endl;

    return out;
}