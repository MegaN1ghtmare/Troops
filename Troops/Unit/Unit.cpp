#include <iostream>
#include "Unit.hpp"
#include "Ability.hpp"
#include "State.hpp"

void Unit::ensureIsAlive() {
   if ( this->hitPoints == 0 ) {
       throw UnitIsDead();
   }
}

Unit::Unit(const std::string& name, int hp, int dmg)
    : State(name, hp, dmg), Ability(damage, hitPoints, hitPointsLimit) {
    if ( hp < 1 || dmg < 1 ) {
        throw UnitIsDead();
    }
}

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
    ensureIsAlive();

    int maxAddHitPoints = getHitPointsLimit() - getHitPoints();

    if ( hp > maxAddHitPoints ) {
        this->hitPoints = this->hitPointsLimit;

        return;
    }

    if ( hp < 0 ) {
        hp *= -1;
    }

    this->hitPoints += hp;
}

void Unit::takeDamage(int dmg) {
    ensureIsAlive();

    if ( dmg >= getHitPoints() ) {
        this->hitPoints = 0;

        return;
    }

    this->hitPoints -= dmg;
}

void Unit::attack(Unit& enemy) {
    enemy.takeDamage(getDamage());

    if ( enemy.hitPoints > 0 ) {
        enemy.counterAttack(*this);
    }
}

void Unit::counterAttack(Unit& enemy) {
    int counterAttackDmg = getDamage() / 2;

    if ( counterAttackDmg > enemy.getHitPoints() ) {
        enemy.hitPoints = 0;

        return;
    }

    enemy.hitPoints -= counterAttackDmg;
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "Unit: " << unit.getName() << ", max HP: " << unit.getHitPointsLimit() << ", current HP: " << unit.getHitPoints() << ", damage: " << unit.getDamage() << std::endl;

    return out;
}
