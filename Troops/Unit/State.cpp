#include <iostream>
#include "State.hpp"

State::State(const std::string& name, int hp, int dmg)
    : name(name), hitPoints(hp), hitPointsLimit(hp),
    damage(dmg) {
}

State::~State() {

}

int State::getDamage() const {
    return this->damage;
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

const std::string& State::getName() const {
    return this->name;
}

std::ostream& operator<<(std::ostream& out, const State& state) {
    out << "State: " << state.getName() << ", max HP: " << state.getHitPointsLimit() << ", current HP: " << state.getHitPoints() << ", damage: " << state.getDamage() << std::endl;

    return out;
}
