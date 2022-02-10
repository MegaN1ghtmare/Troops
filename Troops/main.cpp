#include <iostream>
#include "Unit/Soldier.hpp"
#include "Unit/Unit.hpp"
#include "Unit/Ability.hpp"
#include "Unit/RogueAbility.hpp"
#include "Unit/Rogue.hpp"
#include "Unit/BerserkerAbility.hpp"
#include "Unit/Berserker.hpp"
#include "Unit/VampireAbility.hpp"
#include "Unit/Vampire.hpp"
#include "Unit/WerewolfAbility.hpp"
#include "Unit/Werewolf.hpp"
#include "Unit/Demon.hpp"

#include "SpellCaster/SpellCaster.hpp"
#include "SpellCaster/SpellCasterAbility.hpp"
#include "SpellCaster/Wizard.hpp"
#include "SpellCaster/WizardAbility.hpp"
#include "SpellCaster/Healer.hpp"
#include "SpellCaster/HealerAbility.hpp"
#include "SpellCaster/Priest.hpp"
#include "SpellCaster/PriestAbility.hpp"
#include "SpellCaster/Warlock.hpp"
#include "SpellCaster/WarlockAbility.hpp"
#include "SpellCaster/Necromancer.hpp"

#include "Interfaces/IObserver.hpp"
#include "Interfaces/IObservable.hpp"

#include "Properties/Observer.hpp"
#include "Properties/Observable.hpp"
#include "Properties/UnitClassifier.hpp"

int main() {
    Vampire vampire("VLADIMIR", 444, 56);
    Priest priest("MICHAIL", 9999, 230, 42, 140);
    std::cout << "vampire and priest created:" << std::endl << vampire;
    std::cout << priest << std::endl;

    vampire.attack(priest);
    std::cout << "vampire attack priest:" << std::endl  << vampire;
    std::cout << priest << std::endl;

    priest.attack(vampire);
    std::cout << "priest attack vampire:" << std::endl << vampire;
    std::cout << priest << std::endl;

    Werewolf werewolf("WoofWoof", 600, 30);
    std::cout << "werewolf created: " << std::endl;
    std::cout << werewolf << std::endl;

    std::cout << "priest attack werewolf:" << std::endl;

    for ( int i = 0; i < 2; i++ ) {
      priest.attack(werewolf);
      std::cout << werewolf << std::endl;
      std::cout << priest << std::endl;
    }

    std::cout << "werewolf attack vampire:" << std::endl;
    werewolf.attack(vampire);
    std::cout << werewolf << std::endl;
    std::cout << vampire << std::endl;

    std::cout << "vampire attack werewolf:" << std::endl;
    vampire.attack(werewolf);
    std::cout << werewolf << std::endl;
    std::cout << vampire << std::endl;

    for ( int i = 0; i < 2; i++ ) {
      std::cout << "werewolf attack priest:" << std::endl;
      werewolf.attack(priest);
      std::cout << werewolf << std::endl;
      std::cout << priest << std::endl;
    }

    Warlock warlock("Warlock Warrior", 300, 200, 10, 40);

    std::cout << "warlock attack werewolf:" << std::endl;
    warlock.attack(werewolf);
    std::cout << werewolf << std::endl;
    std::cout << warlock << std::endl;

    std::cout << "warlock attack priest:" << std::endl;
    warlock.attack(priest);
    std::cout << priest << std::endl;
    std::cout << warlock << std::endl;

    std::cout << "warlock attack priest:" << std::endl;
    warlock.attack(priest);
    std::cout << priest << std::endl;
    std::cout << warlock << std::endl;

    Wizard sup("Sup", 100, 150, 5, 25);
    Wizard mag("Mag", 80, 200, 7, 38);
    // std::cout << "mag created:" << std::endl << mag;
    // std::cout << sup << std::endl;

    // sup.attack(mag);
    // std::cout << "sup attack mag:" << std::endl << sup;
    // std::cout << mag << std::endl;

    // mag.attack(sup);
    // std::cout << "mag attack sup:" << std::endl << sup;
    // std::cout << mag << std::endl;

    Berserker bers("Konan", 444, 42);
    std::cout << "bers created: "<< std::endl;
    std::cout << bers << std::endl;

    Soldier sold("sold", 600, 57);
    std::cout << "sold created: "<< std::endl;
    std::cout << sold << std::endl;

    Rogue rog("rog", 333, 33);
    std::cout << "rog created: "<< std::endl;
    std::cout << rog << std::endl;

    std::cout << "warlock attack sold:" << std::endl;
    warlock.attack(sold);
    std::cout << sold << std::endl;
    std::cout << warlock << std::endl;

    Necromancer necromancer("Devil", 250, 150, 25, 60);
    std::cout << "necro created: " << std::endl;
    std::cout << necromancer << std::endl;

    std::cout << "Necro attack sold, ber" << std::endl;
    necromancer.attack(sold);
    necromancer.attack(bers);
    std::cout << sold << std::endl;
    std::cout << bers << std::endl;
    std::cout << necromancer << std::endl;

    std::cout << "Necro attack warlock, mag:" << std::endl;
    necromancer.attack(warlock);
    necromancer.attack(mag);
    std::cout << warlock << std::endl;
    std::cout << mag << std::endl;
    std::cout << necromancer << std::endl;

    // vampire.attack(bers);
    // std::cout << "vampire attack bers:" << std::endl << vampire;
    // std::cout << bers << std::endl;

    // mag.attack(bers);
    // std::cout << "mag attack bers: " << std::endl << mag;
    // std::cout << bers << std::endl;

    // bers.attack(mag);
    // priest.attack(bers);
    // std::cout << "bers attack mag, priest attack bers:" << std::endl << mag << priest;
    // std::cout << vampire;
    // std::cout << bers << std::endl;
  //  std::cout << barbarian->action << std::endl;

    // for ( int i = 1; i < 7; i++ ) {
    //     std::cout << i << " attack" << std::endl;
    //    barbarian.ability();
    //    knight.attack(barbarian);
    //    barbarian.addHitPoints(-3);

    //     std::cout << barbarian.getName();
    //     std::cout << knight << std::endl;
    // }

    return 0;
}
