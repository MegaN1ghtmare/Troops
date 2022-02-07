#include "Demon.hpp"

Demon::Demon(const std::string& name, int hp, int dmg)
    : Unit(name, hp, dmg) {
       this->action = new Ability(damage, hitPoints, hitPointsLimit);
       this->status = new UnitClassifier(1, 0, 1);
       std::cout << "DEMON CREATED" << std::endl;
}

Demon::~Demon() {
        std::cout << "DEMON destroyed" << std::endl;
}

void Demon::takeDamage(int dmg) {
    Unit::takeDamage(dmg);
}

std::ostream& operator<<(std::ostream& out, const Demon& demon) {
    out << "Demon: " << demon.getName() << ", HP:(" << demon.getHitPointsLimit() << "/" << demon.getHitPoints() << "), damage: " << demon.getDamage() << std::endl;

    return out;
}
