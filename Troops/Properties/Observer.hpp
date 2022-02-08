// #ifndef OBSERVER_HPP
// #define OBSERVER_HPP

// #include <iostream>
// #include <map>

// #include "../Interfaces/IObserver.hpp"
// // #include "../SpellCaster/Necromancer.hpp"

// class Observer: public IObserver {
//     protected:
//         std::map<std::string, Unit*>* observerList;
//     public:
//         Observer();
//         virtual ~Observer();

//         virtual void addUnitToList(Unit* observable);
//         virtual void removeUnitFromList(Unit* observable);
//         virtual void clearList();

//         virtual std::map<std::string, Unit*>& getList() const;
// };

// std::ostream& operator<<(std::ostream& out, Observer& observer);

// #endif //OBSERVER_HPP
