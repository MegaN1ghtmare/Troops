#include <iostream>
#include "Unit.hpp"
#include "Ability.hpp"

Unit::Unit(const std::string& name, int hp, int dmg)
    : name(name), hitPoints(hp), hitPointsLimit(hp),
    damage(dmg), action(Ability(&damage, &hitPoints, &hitPointsLimit)) {
    if ( hp < 1 || dmg < 1 ) {
        throw UnitIsDead();
    }
}

Unit::~Unit() {

}

// void Unit::doAction(Unit& enemy) {
//     action.attack(enemy, *this);
// }

int Unit::getDamage() const {
    return this->damage;
}

int Unit::getHitPoints() const {
    return this->hitPoints;
}

int Unit::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

const std::string& Unit::getName() const {
    return this->name;
}

void Unit::addHitPoints(int hp) {
    action.addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
    action.takeDamage(dmg);
}

void Unit::attack(Unit& enemy) {
    action.attack(enemy);
}

void Unit::counterAttack(Unit& enemy) {
    action.counterAttack(enemy);
}


std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Unit: " << unit.getName() << ", max HP: " << unit.getHitPointsLimit() << ", current HP: " << unit.getHitPoints() << ", damage: " << unit.getDamage() << std::endl;

    return out;
}
