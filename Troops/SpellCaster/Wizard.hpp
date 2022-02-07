#ifndef WIZARD_HPP
#define WIZARD_HPP

#include "SpellCaster.hpp"
#include "WizardAbility.hpp"

class WizardAbility;

class Wizard: public SpellCaster {
    public:
        Wizard(const std::string& name, int hp, int mana, int dmg, int mDmg);
        virtual ~Wizard();

        void addManaPoints(int mana) override;
};

std::ostream& operator<<(std::ostream& out, const Wizard& wizard);

#endif //WIZARD_HPP
