#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include "Unit.hpp"
#include "VampireAbility.hpp"

class VampireAbility;

class Vampire: public Unit {
    public:
        Vampire(const std::string& name, int hp, int dmg);
        virtual ~Vampire();

        void takeDamage(int dmg) override;
};

std::ostream& operator<<(std::ostream& out, const Vampire& Vampire);

#endif //VAMPIRE_HPP
