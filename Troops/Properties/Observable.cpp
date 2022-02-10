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

void Observable::deathEvent() {
    std::cout << "Death happened" << std::endl;
}
