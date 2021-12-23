#ifndef SOLDIER_HPP
#define SOLDIER_HPP

#include <iostream>
#include "Unit.hpp"

class Soldier: public Unit {
    public:
        Soldier(const std::string& name, int hp, int dmg);
        virtual ~Soldier();

        virtual void addHitPoints(int hp);
        virtual void takeDamage(int dmg);

        virtual void attack(Soldier& enemy);
        virtual void counterAttack(Soldier& enemy);
};

std::ostream& operator<<(std::ostream& out, const Soldier& soldier);

#endif //SOLDIER_HPP
