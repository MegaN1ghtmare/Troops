#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

// #include <iostream>
#include "Unit.hpp"
// #include "Ability.hpp"
#include "WerewolfAbility.hpp"

// class WerewolfAbilitys;
// class Ability;

class Werewolf: public Unit {
    private:
        int damageWolfForm;
        int hitPointsWolfForm;
        int hitPointsLimitWolfForm;
        int fury;
        int furyToTransformation;

        Ability* currentState;
        Ability* altState;
    public:
        Werewolf(const std::string& name, int hp, int dmg);
        virtual ~Werewolf();

        int getDamage() const;
        int getHitPoints() const;
        int getHitPointsLimit() const;

        int getFury() const;
        int getFuryToTransformation() const;

        void addHitPoints(int hp) override;
        void takeMagicDamage(int dmg) override;
        void takeDamage(int dmg) override;
        void attack(Unit& enemy) override;
        void counterAttack(Unit& enemy) override;

        void transform();
        void transformationCounter(int furyModifier);
        void isObjectDead();
};

std::ostream& operator<<(std::ostream& out, const Werewolf& werewolf);

#endif //WEREWOLF_HPP
