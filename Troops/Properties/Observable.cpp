#include "Observable.hpp"

Observable::Observable(): IObservable() {

}

Observable::~Observable() {

}

void Observable::addObservableToObserverList(Unit* observable, Unit* observer) {
    observer->getObserver()->addUnitToList(observable);
}

void Observable::deathEvent() {

}
