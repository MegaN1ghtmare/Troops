#ifndef DEMON_HPP
#define DEMON_HPP

#include <iostream>
#include "Unit.hpp"
#include "Ability.hpp"

class Ability;

class Demon: public Unit {
    public:
        Demon(const std::string& name, int hp, int dmg);
        virtual ~Demon();

        void takeDamage(int dmg) override;
};

std::ostream& operator<<(std::ostream& out, const Demon& demon);

#endif //DEMON_HPP
