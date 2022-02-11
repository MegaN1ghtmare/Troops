#ifndef UNIT_HPP
#define UNIT_HPP

#include <iostream>
#include "Ability.hpp"
#include "../Properties/UnitClassifier.hpp"
#include "../Properties/Observable.hpp"
#include "../Properties/Observer.hpp"

class Ability;
class UnitClassifier;
class Observable;
class Observer;

class Unit {
    private:
        int damage;
        int hitPoints;
        int hitPointsLimit;
        std::string name;
        Ability* action;
        UnitClassifier* status;
        Observable* observable;
        Observer* observer;
        bool unitAlive = true;
    public:
        Unit(const std::string& name, int hp, int dmg);
        virtual ~Unit();

        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        const std::string& getName() const;

        virtual bool getIfMeleeUnit() const;
        virtual bool getIfAbleToCastUnit() const;
        virtual bool getIfUnitUndead() const;

        virtual bool getUnitAlive() const;
        virtual void setUnitIsDead();
        virtual void checkUnitAlives();

        virtual Observable* getObservable() const;
        virtual Observer* getObserver() const;
        virtual std::map<std::string, Unit*>& getList() const;

        virtual void addHitPoints(int hp);
        virtual void takeDamage(int dmg) = 0;
        virtual void takeMagicDamage(int dmg);

        virtual void attack(Unit& enemy);
        virtual void counterAttack(Unit& enemy);

        friend class Ability;
        friend class Soldier;
        friend class RogueAbility;
        friend class Rogue;
        friend class BerserkerAbility;
        friend class Berserker;
        friend class VampireAbility;
        friend class Vampire;
        friend class SpellCasterAbility;
        friend class SpellCaster;
        friend class WizardAbility;
        friend class Wizard;
        friend class PriestAbility;
        friend class Priest;
        friend class HealerAbility;
        friend class Healer;
        friend class Werewolf;
        friend class WerewolfAbility;
        friend class Demon;
        friend class Warlock;
        friend class WizardAbility;
        friend class Necromancer;
        friend class Observer;
        friend class Observable;
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_HPP
