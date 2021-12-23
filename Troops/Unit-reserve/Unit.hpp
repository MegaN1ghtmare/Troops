#ifndef UNIT_HPP
#define UNIT_HPP

#include <iostream>
#include "Ability.hpp"

class Ability;

class Unit {
    private:
        int damage;
        int hitPoints;
        int hitPointsLimit;
        std::string name;
        Ability action;
    public:
        Unit(const std::string& name, int hp, int dmg);
        virtual ~Unit();

        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        const std::string& getName() const;

  //      virtual void doAction(Unit& enemy);

        virtual void addHitPoints(int hp);
        virtual void takeDamage(int dmg);

        virtual void attack(Unit& enemy);
        virtual void counterAttack(Unit& enemy);

        friend class Ability;
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_HPP
