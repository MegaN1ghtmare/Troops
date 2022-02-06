#include <iostream>
#include "Unit.hpp"
#include "Ability.hpp"

Unit::Unit(const std::string& name, int hp, int dmg)
    : name(name), hitPoints(hp), hitPointsLimit(hp),
    damage(dmg) {

    this->action = new Ability(damage, hitPoints, hitPointsLimit);
    this->status = new UnitClassifier();
    this->observable = new Observable();

    if ( hp < 1 || dmg < 1 ) {
        throw UnitIsDead();
    }
}

Unit::~Unit() {

}

int Unit::getManaPoints() const {
    return 0;
}

int Unit::getManaPointsLimit() const {
    return 0;
}

int Unit::getSpellCost() const {
    return 999999;
}

int Unit::getDamage() const {
    return action->getDamage();
}

int Unit::getHitPoints() const {
    return action->getHitPoints();
}

int Unit::getHitPointsLimit() const {
    return action->getHitPointsLimit();
}

const std::string& Unit::getName() const {
    return this->name;
}

Observable* Unit::getObservable() const {
    return this->observable;
}

bool Unit::getIfMeleeUnit() const {
    return status->getIfMeleeUnit();
}

bool Unit::getIfAbleToCastUnit() const {
    return status->getIfAbleToCastUnit();
}

bool Unit::getIfUnitUndead() const {
    return status->getIfUnitUndead();
}

void Unit::addHitPoints(int hp) {
    action->addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
    action->takeDamage(dmg);
}

void Unit::takeMagicDamage(int dmg) {
    action->takeMagicDamage(dmg);
}

void Unit::attack(Unit& enemy) {
    action->attack(*this, enemy);
}

void Unit::counterAttack(Unit& enemy) {
    action->counterAttack(enemy);
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Unit: " << unit.getName() << ", HP:(" << unit.getHitPointsLimit() << "/" << unit.getHitPoints() << "), damage: " << unit.getDamage() << std::endl;

    return out;
}
