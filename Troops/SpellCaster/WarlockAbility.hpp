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
        int demonCounter;
        std::map <std::string, Demon*> demonMap;
    public:
        WarlockAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~WarlockAbility();

        void magicAttack(SpellCaster& caller, Unit& enemy) override;
        void attack(Unit& caller, Unit& enemy) override;

        void callDemon();

        std::string getDemonMap() const override;
};

#endif //WARLOCKABILITY_HPP
