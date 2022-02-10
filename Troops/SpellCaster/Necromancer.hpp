#ifndef NECROMANCEER_HPP
#define NECROMANCEER_HPP

#include "SpellCaster.hpp"

class Necromancer: public SpellCaster {
    public:
        Necromancer(const std::string& name, int hp, int mana, int dmg, int mDmg);
        virtual ~Necromancer();

        void attack(Unit& enemy) override;

        void addManaPoints(int mana) override;
};

std::ostream& operator<<(std::ostream& out, const Necromancer& necromancer);

#endif //NECROMANCEER_HPP
