#ifndef UNIT_HPP
#define UNIT_HPP

#include <iostream>
#include "Ability.hpp"
#include "../Properties/UnitClassifier.hpp"
// #include "../Properties/Observable.hpp"

class Ability;
class UnitClassifier;
// class Observable;

class Unit {
    private:
        int damage;
        int hitPoints;
        int hitPointsLimit;
        std::string name;
        Ability* action;
        UnitClassifier* status;
        // Observable* observable;
    public:
        Unit(const std::string& name, int hp, int dmg);
        virtual ~Unit();

        int getDamage() const;
        // int getMagicDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;
        const std::string& getName() const;
        // virtual int getManaPoints() const;
        // virtual int getManaPointsLimit() const;
        // virtual int getSpellCost() const;

        virtual bool getIfMeleeUnit() const;
        virtual bool getIfAbleToCastUnit() const;
        virtual bool getIfUnitUndead() const;

        // Observable* getObservable() const;
        // virtual Observer* getObserver() = 0;

        // virtual void addManaPoints(int mana);
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
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif //UNIT_HPP
