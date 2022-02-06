#ifndef PRIESTABILITY_HPP
#define PRIESTABILITY_HPP

#include "SpellCasterAbility.hpp"
#include "PriestAbility.hpp"

class SpellCaster;

class PriestAbility: public SpellCasterAbility {
    public:
        PriestAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~PriestAbility();

        void attack(Unit& caller, Unit& enemy) override;
        void counterAttack(Unit& enemy) override;
        void addManaPoints(int mana) override;
};

#endif //PRIESTABILITY_HPP
