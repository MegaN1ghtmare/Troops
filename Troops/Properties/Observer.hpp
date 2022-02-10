#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>
#include <map>

#include "../Interfaces/IObserver.hpp"
#include "../Unit/Unit.hpp"

class Observer: public IObserver {
    protected:
        std::map<std::string, Unit*>* observerList;
    public:
        Observer();
        virtual ~Observer();

        virtual void addUnitToList(Unit& observable);
        virtual void removeUnitFromList(Unit& observable);
        virtual void clearList();

        virtual std::map<std::string, Unit*>& getList() const;
};

template<typename First, typename Second>
std::ostream& operator<<(std::ostream& out, const std::map<First, Second>& lst);

std::ostream& operator<<(std::ostream& out, const Observer& observer);

#endif //OBSERVER_HPP
