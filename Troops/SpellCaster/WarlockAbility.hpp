#ifndef WARLOCKABILITY_HPP
#define WARLOCKABILITY_HPP

#include <iostream>
#include <sstream>
#include <map>
#include "SpellCasterAbility.hpp"
#include "SpellCaster.hpp"
#include "../Unit/Demon.hpp"

class WarlockAbility: public SpellCasterAbility {
    private:
        int callDemonManaCost;
    public:
        WarlockAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~WarlockAbility();

        void magicAttack(SpellCaster& caller, Unit& enemy) override;

        void callDemon();
};

#endif //WARLOCKABILITY_HPP
