#include "Vampire.hpp"

Vampire::Vampire(const std::string& name, int hp, int dmg)
    : Unit(name, hp, dmg) {
       this->action = new VampireAbility(damage, hitPoints, hitPointsLimit);
       this->status = new UnitClassifier(1, 0, 1);
}

Vampire::~Vampire() {

}

void Vampire::takeDamage(int dmg) {
    Unit::takeDamage(dmg);
}

std::ostream& operator<<(std::ostream& out, const Vampire& vampire) {
    out << "Vampire: " << vampire.getName() << ", HP:(" << vampire.getHitPointsLimit() << "/" << vampire.getHitPoints() << "), damage: " << vampire.getDamage() << std::endl;

    return out;
}
