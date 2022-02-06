#ifndef HEALER_HPP
#define HEALER_HPP

#include <iostream>
#include "SpellCaster.hpp"
#include "HealerAbility.hpp"

class HealerAbility;

class Healer: public SpellCaster {
    public:
        Healer(const std::string& name, int hp, int mana, int dmg, int mDmg);
        virtual ~Healer();

        void takeDamage(int dmg) override;

        void addManaPoints(int mana) override;
};

std::ostream& operator<<(std::ostream& out, const Healer& healer);

#endif //HEALER_HPP
