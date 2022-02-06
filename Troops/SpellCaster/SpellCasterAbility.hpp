#ifndef SPELLCASTERABILITY_HPP
#define SPELLCASTERABILITY_HPP

#include "../Unit/Ability.hpp"
#include "SpellCaster.hpp"

class SpellCaster;

class SpellCasterIsDead {};

class SpellCasterAbility : public Ability {
    protected:
        int& damage;
        int& magicDamage;
        int& hitPoints;
        int& hitPointsLimit;
        int& manaPoints;
        int& manaPointsLimit;
        int& spellCost;
        void ensureIsAlive();
    public:
        SpellCasterAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~SpellCasterAbility();

        int& getDamage() const;
        int& getMagicDamage() const;
        int& getManaPoints() const;
        int& getManaPointsLimit() const;
        int& getHitPoints() const;
        int& getHitPointsLimit() const;
        int& getSpellCost() const;
        const std::string& getName() const;

        void addHitPoints(int hp) override;
        virtual void addManaPoints(int mana);
        void takeDamage(int dmg) override;
        void takeMagicDamage(int dmg) override;

        void attack(Unit& caller, Unit& enemy) override;
        void counterAttack(Unit& enemy) override;
};

#endif //SPELLCASTERABILITY_HPP
