#include <iostream>
#include "Unit.hpp"
#include "Ability.hpp"

Unit::Unit(const std::string& name, int hp, int dmg)
    : name(name), hitPoints(hp), hitPointsLimit(hp),
    damage(dmg) {

    this->action = new Ability(damage, hitPoints, hitPointsLimit);
    this->status = new UnitClassifier();
    this->observable = new Observable();
    this->observer = new Observer();

    if ( hp < 1 || dmg < 1 ) {
        throw UnitIsDead();
    }
}

Unit::~Unit() {

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

Observer* Unit::getObserver() const {
    return this->observer;
}

std::map<std::string, Unit*>& Unit::getList() const {
    return observer->getList();
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

bool Unit::getUnitAlive() const {
    return this->unitAlive;
}

void Unit::checkUnitAlives() {
    if ( getHitPoints() <= 0 ) {
        setUnitIsDead();
    }
}

void Unit::setUnitIsDead() {
    this->unitAlive = false;

    observable->deathEvent(*this);
}

void Unit::addHitPoints(int hp) {
    action->addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
    action->takeDamage(dmg);
    checkUnitAlives();
}

void Unit::takeMagicDamage(int dmg) {
    action->takeMagicDamage(dmg);
    checkUnitAlives();
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
