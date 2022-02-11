#include "Observable.hpp"

Observable::Observable(): IObservable() {
    this->observableList = new std::map<std::string, Unit*>;
}

Observable::~Observable() {
    delete(observableList);
}

void Observable::addObservableToObserverList(Unit& observable, Unit& observer) {
    observer.getObserver()->addUnitToList(observable);
    this->observableList->insert(std::pair<std::string, Unit*>(observer.getName(), &observer));
}

void Observable::deathEvent(Unit& observable) {
    std::cout << "Death happened" << std::endl;
    for ( auto it = observableList->begin(); it != observableList->end(); it++ ) {
        Unit* unitObserver = (it->second);
        Observer* observer = unitObserver->getObserver();

        observer->observableDeathEvent(observable, *unitObserver);
    }
}
