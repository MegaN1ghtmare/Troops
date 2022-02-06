#ifndef BERSERKERABILITY_HPP
#define BERSERKERABILITY_HPP

#include "Ability.hpp"

class Unit;

class BerserkerAbility : public Ability {
    public:
        BerserkerAbility(int& dmg, int& hp, int& hpLimits);
        virtual ~BerserkerAbility();

        void takeMagicDamage(int dmg) override;
        void counterAttack(Unit& enemy) override;
};

#endif //BERSERKERABILITY_HPP
