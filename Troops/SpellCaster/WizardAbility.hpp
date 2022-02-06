#ifndef WIZARDABILITY_HPP
#define WIZARDABILITY_HPP

#include "SpellCasterAbility.hpp"

class SpellCaster;

class WizardAbility: public SpellCasterAbility {
    public:
        WizardAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~WizardAbility();

        void attack(Unit& caller, Unit& enemy) override;
        void addManaPoints(int mana) override;
};

#endif //WIZARDABILITY_HPP
