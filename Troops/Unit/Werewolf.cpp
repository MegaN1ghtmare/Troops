#include "Werewolf.hpp"

#define WEREWOLFDMGMLTP 3
#define WEREWOLFHPMLTP 4

Werewolf::Werewolf(const std::string& name, int hp, int dmg)
    : Unit(name, hp, dmg),
    damageWolfForm(dmg * WEREWOLFDMGMLTP), hitPointsWolfForm(hp * WEREWOLFHPMLTP),
    hitPointsLimitWolfForm(hp * WEREWOLFHPMLTP) {

        this->fury = 0;
        this->furyToTransformation = 10;

        this->currentState = action;
        this->altState = new WerewolfAbility(damageWolfForm, hitPointsWolfForm, hitPointsLimitWolfForm);
}

Werewolf::~Werewolf() {

}

int Werewolf::getDamage() const {
    return currentState->getDamage();
}

int Werewolf::getHitPoints() const {
    return currentState->getHitPoints();
}

int Werewolf::getHitPointsLimit() const {
    return currentState->getHitPointsLimit();
}

int Werewolf::getFury() const {
    return this->fury;
}

int Werewolf::getFuryToTransformation() const {
    return this->furyToTransformation;
}

void Werewolf::addHitPoints(int hp) {
    currentState->addHitPoints(hp);
}

void Werewolf::takeDamage(int dmg) {
    currentState->takeDamage(dmg);
    isObjectDead();
    transformationCounter(1);
}

void Werewolf::takeMagicDamage(int dmg) {
    currentState->takeMagicDamage(dmg);
    isObjectDead();
    transformationCounter(3);
}

void Werewolf::attack(Unit& enemy) {
    currentState->attack(*this, enemy);
    transformationCounter(2);
}

void Werewolf::counterAttack(Unit& enemy) {
    currentState->counterAttack(enemy);
}

void Werewolf::isObjectDead() {
    if ( getHitPoints() == 0 ) {
        int deathDmg = altState->getHitPoints();

        altState->takeDamage(deathDmg);
    }
}

void Werewolf::transform() {
    Ability* tmpState = currentState;
    currentState = altState;
    altState = tmpState;

    if ( getFuryToTransformation() == 10 ) {
        furyToTransformation = 0;
    } else {
        furyToTransformation = 10;
    }
}

void Werewolf::transformationCounter(int furyModifier) {
    int maxFuryModify = getFuryToTransformation() - getFury();
    if ( maxFuryModify < 0 ) {
        maxFuryModify *= -1;
    }

    if ( furyModifier > maxFuryModify ) {
        furyModifier = maxFuryModify;
    }

    if ( getFury() < getFuryToTransformation() ) {
        fury += furyModifier;
    } else if ( getFury() == getFuryToTransformation() ) {
        transform();
    } else {
        fury -= furyModifier;
    }
}

std::ostream& operator<<(std::ostream& out, const Werewolf& werewolf) {
    out << "Werewolf: " << werewolf.getName() << ", HP:(" << werewolf.getHitPointsLimit() << "/" << werewolf.getHitPoints() << "), damage: " << werewolf.getDamage() << std::endl;

    return out;
}
