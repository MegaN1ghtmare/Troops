#ifndef ABILITY_HPP
#define ABILITY_HPP

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

        int& getDamage() const;
        int& getHitPoints() const;
        int& getHitPointsLimit() const;
        const std::string& getName() const;

        virtual void addHitPoints(int hp);
        virtual void takeDamage(int dmg);
        virtual void takeMagicDamage(int dmg);

        virtual void attack(Unit& caller, Unit& enemy);
        virtual void counterAttack(Unit& enemy);
};

#endif //ABILITY_HPP
