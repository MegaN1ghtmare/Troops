#ifndef HEALERABILITY_HPP
#define HEALERABILITY_HPP

#include "SpellCasterAbility.hpp"
#include "SpellCaster.hpp"

class HealerAbility: public SpellCasterAbility {
    public:
        HealerAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~HealerAbility();

        void magicAttack(SpellCaster& caller, Unit& enemy) override;
};

#endif //HEALERABILITY_HPP
