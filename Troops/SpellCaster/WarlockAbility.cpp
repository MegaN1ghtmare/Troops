#include <iostream>
#include <sstream>
#include <map>
#include "WarlockAbility.hpp"
#include "SpellCaster.hpp"

WarlockAbility::WarlockAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : SpellCasterAbility(dmg, mDmg, hp, hpLimits, manaPoints, mpLimits, sCost) {
        this->callDemonManaCost = manaPointsLimit * 0.5;
}

WarlockAbility::~WarlockAbility() {

}

void WarlockAbility::attack(Unit& caller, Unit& enemy) {
    if ( caller.getManaPoints() >= callDemonManaCost ) {
        callDemon();
        manaPoints -= callDemonManaCost;
        return;
    } else if ( caller.getManaPoints() >= caller.getSpellCost() ) {
        enemy.takeMagicDamage(getMagicDamage());
        manaPoints -= caller.getSpellCost();
    } else {
        enemy.takeDamage(getDamage());
    }

    caller.addManaPoints(getManaPointsLimit() * 0.03);



    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }
}

void WarlockAbility::addManaPoints(int mana) {
    SpellCasterAbility::addManaPoints(mana);
}

void WarlockAbility::callDemon() {
    int demonCounter = 1;
    std::string demonName = "Demon-";

    std::stringstream ss;
    ss << demonCounter;
    demonName += ss.str();

    Demon demon(demonName, 100, 10);
    std::map <std::string, int> demonMap;
    demonMap.insert ( std::pair<std::string, int>(demonName, demonCounter) );

      for (auto it = demonMap.begin(); it != demonMap.end(); ++it)
      {
          std::cout << it->first << std::endl;
      }

    demonCounter += 1;
}