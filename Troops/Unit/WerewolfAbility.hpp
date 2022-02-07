#ifndef WEREWOLFABILITY_HPP
#define WEREWOLFABILITY_HPP

#include "Ability.hpp"
#include "Unit.hpp"

class Unit;

class WerewolfAbility : public Ability {
    public:
        WerewolfAbility(int& dmg, int& hp, int& hpLimits);
        virtual ~WerewolfAbility();

        void takeMagicDamage(int dmg) override;
        void takeDamage(int dmg) override;
};

#endif //WEREWOLFABILITY_HPP
