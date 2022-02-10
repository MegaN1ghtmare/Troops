#ifndef SPELLCASTER_HPP
#define SPELLCASTER_HPP

#include "SpellCasterAbility.hpp"
#include "../Unit/Unit.hpp"

class Unit;
class SpellCasterAbility;

class SpellCaster: public Unit {
    private:
        int magicDamage;
        int manaPoints;
        int manaPointsLimit;
        int spellCost;
        std::string name;
        SpellCasterAbility* action;
    public:
        SpellCaster(const std::string& name, int hp, int mana, int dmg, int mDmg);
        virtual ~SpellCaster();

        // int getDamage() const;
        int getMagicDamage() const;
        int getManaPoints() const;
        int getManaPointsLimit() const;
        // int getHitPoints() const;
        // int getHitPointsLimit() const;
        int getSpellCost() const;
        // const std::string& getName() const;

        // void addHitPoints(int hp) override;
        virtual void addManaPoints(int mana) = 0;
        void takeDamage(int dmg) override;
        // void takeMagicDamage(int dmg) override;

        void attack(Unit& enemy) override;
        // void counterAttack(Unit& enemy) override;

        friend class Ability;
        friend class Soldier;
        friend class RogueAbility;
        friend class Rogue;
        friend class BerserkerAbility;
        friend class Berserker;
        friend class VampireAbility;
        friend class Vampire;
        friend class SpellCasterAbility;
        friend class Unit;
        friend class WizardAbility;
        friend class Wizard;
        friend class PriestAbility;
        friend class Priest;
        friend class HealerAbility;
        friend class Healer;
        friend class Warlock;
        friend class WizardAbility;
        friend class Necromancer;
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster);

#endif //SPELLCASTER_HPP
