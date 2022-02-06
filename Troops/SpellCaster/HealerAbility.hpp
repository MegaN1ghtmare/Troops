#ifndef HEALERABILITY_HPP
#define HEALERABILITY_HPP

#include "SpellCasterAbility.hpp"

class SpellCaster;

class HealerAbility: public SpellCasterAbility {
    public:
        HealerAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~HealerAbility();

        void attack(Unit& caller, Unit& enemy) override;
        void addManaPoints(int mana) override;
};

#endif //HEALERABILITY_HPP
