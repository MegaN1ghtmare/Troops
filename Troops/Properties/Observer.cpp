#include "Observer.hpp"

Observer::Observer(): IObserver() {
    this->observerList = new std::map<std::string, Unit*>;
}

Observer::~Observer() {
    delete(observerList);
}

void Observer::addUnitToList(Unit& observable) {
    this->observerList->insert(std::pair<std::string, Unit*>(observable.getName(), &observable));
}

void Observer::removeUnitFromList(Unit& observable) {
    this->observerList->erase(observable.getName());
}

void Observer::clearList() {
    this->observerList->clear();
}

void Observer::observableDeathEvent(Unit& observable, Unit& observer) {
    observer.addHitPoints(observable.getHitPointsLimit() / 4);

    removeUnitFromList(observable);
}

std::map<std::string, Unit*>& Observer::getList() const {
    return *observerList;
}

template<typename First, typename Second>
std::ostream& operator<<(std::ostream& out, const std::map<First, Second>& lst) {
    typename std::map<First, Second>::const_iterator it = lst.begin();

    for ( ; it != lst.end(); it++ ) {
        out << "- " << it->first << std::endl;
    }

    return out;
}

std::ostream& operator<<(std::ostream& out, const Observer& observer) {
    out << "Observer List: " << observer.getList() << std::endl;

    return out;
}
