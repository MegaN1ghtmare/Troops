#include "Wizard.hpp"

Wizard::Wizard(const std::string& name, int hp, int mana, int dmg, int mDmg)
    : SpellCaster(name, hp, mana, dmg, mDmg) {

    this->spellCost = 20;

    this->action = new WizardAbility(damage, magicDamage, hitPoints, hitPointsLimit, manaPoints, manaPointsLimit, spellCost);
    this->status = new UnitClassifier(1, 1, 0);
}

Wizard::~Wizard() {

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
