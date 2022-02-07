#ifndef VAMPIREABILITY_HPP
#define VAMPIREABILITY_HPP

#include "Ability.hpp"
#include "Unit.hpp"

class Unit;

class VampireAbility : public Ability {
    public:
        VampireAbility(int& dmg, int& hp, int& hpLimits);
        virtual ~VampireAbility();

        void attack(Unit& caller, Unit& enemy) override;
        void counterAttack(Unit& enemy) override;
};

#endif //VAMPIREABILITY_HPP
