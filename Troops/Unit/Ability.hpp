#ifndef ABILITY_HPP
#define ABILITY_HPP

class State;
class Unit;

class UnitIsDead {};

class Ability {
    protected:
        int& damage;
        int& hitPoints;
        int& hitPointsLimit;
        void ensureIsAlive();
    public:
        Ability(int& dmg, int& hp, int& hpLimits);
        virtual ~Ability();

        virtual void addHitPoints(int hp);
        virtual void takeDamage(int dmg);

        virtual void attack(Unit& enemy);
        virtual void counterAttack(Unit& enemy);

        friend class State;
};

#endif //ABILITY_HPP
