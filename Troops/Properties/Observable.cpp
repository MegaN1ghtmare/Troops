#include "Observable.hpp"

Observable::Observable(): IObservable() {
    this->observableList = new std::map<std::string, Unit*>;
}

Observable::~Observable() {
    delete(observableList);
    std::cout << "Observable map deleted" << std::endl;
}

void Observable::addObservableToObserverList(Unit& observable, Unit& observer) {
    observer.getObserver()->addUnitToList(observable);
    this->observableList->insert(std::pair<std::string, Unit*>(observer.getName(), &observer));
    std::cout << "addObservableToObserverList " << observer << std::endl;
    for ( auto it = observableList->begin(); it != observableList->end(); it++ ) {
        std::cout << "CHEEEECKKKKKING" << std::endl;
        Unit* unitObserver = (it->second);
        Observer* observer = unitObserver->getObserver();
std::cout << "(it->second) " << *(unitObserver) << std::endl;
std::cout << "unitObserver " << observer << std::endl;
    }
}

void Observable::deathEvent(Unit& observable) {
    std::cout << "Death happened" << std::endl;
    for ( auto it = observableList->begin(); it != observableList->end(); it++ ) {
        std::cout << "WHAT DA FUCK" << std::endl;
        Unit* unitObserver = (it->second);
        Observer* observer = unitObserver->getObserver();
std::cout << "(it->second) " << unitObserver << std::endl;
std::cout << "unitObserver " << observer << std::endl;
        observer->observableDeathEvent(observable, *unitObserver);
    }
    std::cout << "event ended" << std::endl;
}
