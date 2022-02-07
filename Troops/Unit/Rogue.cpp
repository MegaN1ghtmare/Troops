#include "Rogue.hpp"

Rogue::Rogue(const std::string& name, int hp, int dmg)
    : Unit(name, hp, dmg) {
       this->action = new RogueAbility(damage, hitPoints, hitPointsLimit);
       this->status = new UnitClassifier();
}

Rogue::~Rogue() {

}

void Rogue::takeDamage(int dmg) {
    Unit::takeDamage(dmg);
}

std::ostream& operator<<(std::ostream& out, const Rogue& rogue) {
    out << "Rogue: " << rogue.getName() << ", HP:(" << rogue.getHitPointsLimit() << "/" << rogue.getHitPoints() << "), damage: " << rogue.getDamage() << std::endl;

    return out;
}
