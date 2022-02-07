#ifndef ROGUEABILITY_HPP
#define ROGUEABILITY_HPP

#include "Ability.hpp"

// class Unit;

class RogueAbility : public Ability {
    public:
        RogueAbility(int& dmg, int& hp, int& hpLimits);
        virtual ~RogueAbility();

        void attack(Unit& caller, Unit& enemy) override;
};

#endif //ROGUEABILITY_HPP
