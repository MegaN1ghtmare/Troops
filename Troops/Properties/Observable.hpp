#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "../Interfaces/IObservable.hpp"
#include "../Unit/Unit.hpp"

class Observable: public IObservable {
    protected:
        std::map<std::string, Unit*>* observableList;
    public:
        Observable();
        virtual ~Observable();

        virtual void addObservableToObserverList(Unit& observable, Unit& observer);
        virtual void deathEvent(Unit& observable);
};

#endif //OBSERVABLE_HPP
