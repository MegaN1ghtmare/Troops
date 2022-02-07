#ifndef PRIEST_HPP
#define PRIEST_HPP

#include "SpellCaster.hpp"
#include "PriestAbility.hpp"

class PriestAbility;

class Priest: public SpellCaster {
    public:
        Priest(const std::string& name, int hp, int mana, int dmg, int mDmg);
        virtual ~Priest();

        void addManaPoints(int mana) override;
};

std::ostream& operator<<(std::ostream& out, const Priest& priest);

#endif //PRIEST_HPP
