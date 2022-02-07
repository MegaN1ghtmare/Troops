#ifndef PRIESTABILITY_HPP
#define PRIESTABILITY_HPP

#include "SpellCasterAbility.hpp"
#include "SpellCaster.hpp"

class PriestAbility: public SpellCasterAbility {
    public:
        PriestAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~PriestAbility();

        void magicAttack(SpellCaster& caller, Unit& enemy) override;
        void counterAttack(Unit& enemy) override;
};

#endif //PRIESTABILITY_HPP
