#ifndef ROGUE_HPP
#define ROGUE_HPP

#include <iostream>
#include "Unit.hpp"
#include "RogueAbility.hpp"

class RogueAbility;

class Rogue: public Unit {
    public:
        Rogue(const std::string& name, int hp, int dmg);
        virtual ~Rogue();

        void takeDamage(int dmg) override;
};

std::ostream& operator<<(std::ostream& out, const Rogue& rogue);

#endif //ROGUE_HPP
