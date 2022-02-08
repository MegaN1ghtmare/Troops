// #include "Observer.hpp"

// Observer::Observer(): IObserver() {
//     this->observerList = new std::map<std::string, Unit*>();
// }

// Observer::~Observer() {
//     delete(observerList);
// }

// void Observer::addUnitToList(Unit* observable) {
//     this->observerList->insert(std::pair<std::string, Unit*>(observable->getName(), observable));
// }

// void Observer::removeUnitFromList(Unit* observable) {
//     this->observerList->erase(observable->getName());
// }

// void Observer::clearList() {
//     this->observerList->clear();
// }

// std::map<std::string, Unit*>& Observer::getList() const {
//     return *observerList;
// }

// std::ostream& operator<<(std::ostream& out, const Observer& observer) {
//     out << "Observer List: " << observer.getList() << std::endl;

//     return out;
// }
