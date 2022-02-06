#ifndef UNITCLASSIFIER_HPP
#define UNITCLASSIFIER_HPP

#include "../Unit/Unit.hpp"

class UnitClassifier {
    private:
        bool melee;
        bool ableToCast;
        bool undead;
    public:
        UnitClassifier(bool melee=1, bool ableToCast=0, bool undead=0);
        virtual ~UnitClassifier();

        virtual bool getIfMeleeUnit() const;
        virtual bool getIfAbleToCastUnit() const;
        virtual bool getIfUnitUndead() const;

        void meleeToRange();
        void rangeToMelee();
        void becomeCaster();
        void becomeUndead();

        friend class Unit;
        friend class SpellCaster;
};

#endif //UNITCLASSIFIER_HPP
