#include <iostream>
#include "Ability.hpp"
#include "Unit.cpp"

class Unit;

void Ability::ensureIsAlive() {
   if ( this->hitPoints == 0 ) {
       throw UnitIsDead();
   }
}

Ability::Ability(int* dmg, int* hp, int* hpLimits)
    : damage(dmg), hitPoints(hp), hitPointsLimit(hp) {
}

Ability::~Ability() {

}

int& Ability::getDamage() const {
    return *damage;
}

int& Ability::getHitPoints() const {
    return *hitPoints;
}

int& Ability::getHitPointsLimit() const {
    return *hitPointsLimit;
}

void Ability::addHitPoints(int hp) {
    ensureIsAlive();

    int maxAddHitPoints = getHitPointsLimit() - getHitPoints();

    if ( hp > maxAddHitPoints ) {
        *hitPoints = *hitPointsLimit;

        return;
    }

    if ( hp < 0 ) {
        hp *= -1;
    }

    *hitPoints += hp;
}

void Ability::takeDamage(int dmg) {
    ensureIsAlive();

    if ( dmg >= getHitPoints() ) {
        *hitPoints = 0;

        return;
    }

    *hitPoints -= dmg;
}

void Ability::attack(Unit& enemy) {
    enemy.takeDamage(getDamage());

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(*this);
    }
}

void Ability::counterAttack(Unit& enemy) {
    int counterAttackDmg = getDamage() / 2;

    if ( counterAttackDmg > enemy.getHitPoints() ) {
        enemy.hitPoints = 0;

        return;
    }

    enemy.hitPoints -= counterAttackDmg;
}