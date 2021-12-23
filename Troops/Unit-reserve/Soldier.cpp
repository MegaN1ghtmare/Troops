#include "Soldier.hpp"
#include "Unit.cpp"

Soldier::Soldier(const std::string& name, int hp, int dmg) : Unit(name, hp, dmg) {

}

Soldier::~Soldier() {

}

void Soldier::attack(Unit& enemy) {
    enemy.takeDamage(getDamage());

    if ( enemy.hitPoints > 0 ) {
        enemy.counterAttack(*this);
    }
}

void Soldier::counterAttack(Unit& enemy) {
    int counterAttackDmg = getDamage() / 2;

    if ( counterAttackDmg > enemy.getHitPoints() ) {
        enemy.hitPoints = 0;

        return;
    }

    enemy.hitPoints -= counterAttackDmg;
}

std::ostream& operator<<(std::ostream& out, const Soldier& soldier) {
    out << "Soldier: " << soldier.getName() << ", max HP: " << soldier.getHitPointsLimit() << ", current HP: " << soldier.getHitPoints() << ", damage: " << soldier.getDamage() << std::endl;

    return out;
}
