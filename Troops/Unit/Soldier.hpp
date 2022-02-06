#ifndef SOLDIER_HPP
#define SOLDIER_HPP

#include <iostream>
#include "Unit.hpp"
#include "Ability.hpp"

class Ability;
class UnitClassifier;

class Soldier: public Unit {
    public:
        Soldier(const std::string& name, int hp, int dmg);
        virtual ~Soldier();

        void takeDamage(int dmg) override;
};

std::ostream& operator<<(std::ostream& out, const Soldier& soldier);

#endif //SOLDIER_HPP
