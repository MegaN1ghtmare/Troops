#ifndef IOBSERVABLE_HPP
#define IOBSERVABLE_HPP

#include <string>
#include <map>

class Unit;

class IObservable {
    public:
        IObservable();
        virtual ~IObservable();

        virtual void addObservableToObserverList(Unit& observable, Unit& observer) = 0;
        virtual void deathEvent(Unit& observable) = 0;
};

#endif //IOBSERVABLE_HPP
