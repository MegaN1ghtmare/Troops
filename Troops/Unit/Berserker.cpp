#include "Berserker.hpp"

Berserker::Berserker(const std::string& name, int hp, int dmg)
    : Unit(name, hp, dmg) {
       this->action = new BerserkerAbility(damage, hitPoints, hitPointsLimit);
       this->status = new UnitClassifier();
}

Berserker::~Berserker() {

}

void Berserker::takeDamage(int dmg) {
    Unit::takeDamage(dmg);
}

std::ostream& operator<<(std::ostream& out, const Berserker& berserker) {
    out << "Berserker: " << berserker.getName() << ", HP:(" << berserker.getHitPointsLimit() << "/" << berserker.getHitPoints() << "), damage: " << berserker.getDamage() << std::endl;

    return out;
}
