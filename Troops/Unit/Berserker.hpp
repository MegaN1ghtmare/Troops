#ifndef BERSERKER_HPP
#define BERSERKER_HPP

#include <iostream>
#include "Unit.hpp"
#include "BerserkerAbility.hpp"

class BerserkerAbility;

class Berserker: public Unit {
    public:
        Berserker(const std::string& name, int hp, int dmg);
        virtual ~Berserker();

        void takeDamage(int dmg) override;
};

std::ostream& operator<<(std::ostream& out, const Berserker& berserker);

#endif //BERSERKER_HPP
