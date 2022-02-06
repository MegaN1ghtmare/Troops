#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include "SpellCaster.hpp"
#include "WarlockAbility.hpp"

class WarlockAbility;

class Warlock: public SpellCaster {
    public:
        Warlock(const std::string& name, int hp, int mana, int dmg, int mDmg);
        virtual ~Warlock();

        void takeDamage(int dmg) override;

        void addManaPoints(int mana) override;
};

std::ostream& operator<<(std::ostream& out, const Warlock& warlock);

#endif //WARLOCK_HPP