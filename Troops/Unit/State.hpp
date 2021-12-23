#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include "Ability.hpp"

class State {
    protected:
        int damage;
        int hitPoints;
        int hitPointsLimit;
        std::string name;
    public:
        State(const std::string& name, int hp, int dmg);
        virtual ~State();

        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        const std::string& getName() const;

        friend class Ability;
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif //STATE_HPP