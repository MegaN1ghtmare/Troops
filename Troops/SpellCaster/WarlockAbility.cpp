#include "WarlockAbility.hpp"

WarlockAbility::WarlockAbility(int& dmg, int& mDmg, int& hp, int& hpLimits, int& manaPoints, int& mpLimits, int& sCost)
    : SpellCasterAbility(dmg, mDmg, hp, hpLimits, manaPoints, mpLimits, sCost) {
        this->callDemonManaCost = manaPointsLimit * 0.5;
        this->demonCounter = 1;
}

WarlockAbility::~WarlockAbility() {

}

void WarlockAbility::magicAttack(SpellCaster& caller, Unit& enemy) {
    if ( caller.getManaPoints() >= callDemonManaCost ) {
        callDemon();
        manaPoints -= callDemonManaCost;
        return;
    }

    enemy.takeMagicDamage(getMagicDamage());
    manaPoints -= caller.getSpellCost();

    if ( demonMap.empty() != true ) {
        for ( auto it = demonMap.begin(); it != demonMap.end(); it++ ) {
            (*(it->second)).attack(enemy);
        }
    }

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }

    caller.addManaPoints(getManaPointsLimit() * 0.03);
}

void WarlockAbility::attack(Unit& caller, Unit& enemy) {
    enemy.takeDamage(getDamage());

    if ( demonMap.empty() != true ) {
        for ( auto it = demonMap.begin(); it != demonMap.end(); it++ ) {
            (*(it->second)).attack(enemy);
        }
    }

    if ( enemy.getHitPoints() > 0 ) {
        enemy.counterAttack(caller);
    }
}

void WarlockAbility::callDemon() {
    std::string demonName = "Demon-";

    std::stringstream ss;
    ss << demonCounter;
    demonName += ss.str();

    Demon* demon = new Demon(demonName, 100, 10);

    demonMap.insert ( std::pair<std::string, Demon*>(demonName, demon) );

      for ( auto it = demonMap.begin(); it != demonMap.end(); it++ ) {
          std::cout << it->first << std::endl;
      }

    demonCounter += 1;
}

std::string WarlockAbility::getDemonMap() const {
    std::string out;

    std::stringstream ss;
    for ( auto it = demonMap.begin(); it != demonMap.end(); it++ ) {
        ss << *(it->second);
    }
    out += ss.str();

    return out;
}
