#include "UnitClassifier.hpp"

UnitClassifier::UnitClassifier(bool melee, bool ableToCast, bool undead)
    : melee(melee), ableToCast(ableToCast), undead(undead) {

}

UnitClassifier::~UnitClassifier() {

}

bool UnitClassifier::getIfMeleeUnit() const {
    return this->melee;
}

bool UnitClassifier::getIfAbleToCastUnit() const {
    return this->ableToCast;
}

bool UnitClassifier::getIfUnitUndead() const {
    return this->undead;
}

void UnitClassifier::meleeToRange() {
    melee = 0;
}

void UnitClassifier::rangeToMelee() {
    melee = 1;
}

void UnitClassifier::becomeCaster() {
    ableToCast = 1;
}

void UnitClassifier::becomeUndead() {
    undead = 1;
}
