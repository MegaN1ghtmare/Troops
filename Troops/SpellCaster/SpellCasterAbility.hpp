#ifndef SPELLCASTERABILITY_HPP
#define SPELLCASTERABILITY_HPP

#include "SpellCaster.hpp"
#include "../Unit/Ability.hpp"

class SpellCaster;

class SpellCasterAbility: public Ability {
    protected:
        int& magicDamage;
        int& manaPoints;
        int& manaPointsLimit;
        int& spellCost;
    public:
        SpellCasterAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost);
        virtual ~SpellCasterAbility();

        int& getMagicDamage() const;
        int& getManaPoints() const;
        int& getManaPointsLimit() const;
        int& getSpellCost() const;

        virtual void addManaPoints(int mana);
        virtual void magicAttack(SpellCaster& caller, Unit& enemy);

        virtual std::string getDemonMap() const;
};

#endif //SPELLCASTERABILITY_HPP
