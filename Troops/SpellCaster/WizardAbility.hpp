#ifndef WIZARDABILITY_HPP
#define WIZARDABILITY_HPP

#include "SpellCasterAbility.hpp"
#include "SpellCaster.hpp"

class WizardAbility: public SpellCasterAbility {
    public:
        WizardAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~WizardAbility();

        void addHitPoints(int hp) override;

        void magicAttack(SpellCaster& caller, Unit& enemy) override;
};

#endif //WIZARDABILITY_HPP
