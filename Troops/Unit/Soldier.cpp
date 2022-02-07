#include "Soldier.hpp"

Soldier::Soldier(const std::string& name, int hp, int dmg)
    : Unit(name, hp, dmg) {
        this->status = new UnitClassifier();
}

Soldier::~Soldier() {

}

void Soldier::takeDamage(int dmg) {
    Unit::takeDamage(dmg);
}

std::ostream& operator<<(std::ostream& out, const Soldier& soldier) {
    out << "Soldier: " << soldier.getName() << ", HP:(" << soldier.getHitPointsLimit() << "/" << soldier.getHitPoints() << "), damage: " << soldier.getDamage() << std::endl;

    return out;
}
