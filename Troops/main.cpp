#include <iostream>
#include "Unit/Soldier.hpp"
#include "Unit/Unit.hpp"
#include "Unit/Ability.hpp"

int main() {
    Unit barbarian("Barbarian", 100, 18);
    Unit knight("Knight", 200, 25);

    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;

    barbarian.attack(knight);

    std::cout << barbarian << std::endl;
    std::cout << knight << std::endl;
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
