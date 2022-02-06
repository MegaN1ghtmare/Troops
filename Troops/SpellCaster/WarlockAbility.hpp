#ifndef WARLOCKABILITY_HPP
#define WARLOCKABILITY_HPP

#include "SpellCasterAbility.hpp"
#include "../Unit/Demon.hpp"

class SpellCaster;

class WarlockAbility: public SpellCasterAbility {
    private:
        int callDemonManaCost;
    public:
        WarlockAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~WarlockAbility();

        void attack(Unit& caller, Unit& enemy) override;
        void addManaPoints(int mana) override;

        void callDemon();
};

#endif //WARLOCKABILITY_HPP
