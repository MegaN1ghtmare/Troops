#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <string>
#include <map>

class Unit;

class IObserver {
    public:
        IObserver();
        virtual ~IObserver();

        virtual void addUnitToList(Unit& observable) = 0;
        virtual void removeUnitFromList(Unit& observable) = 0;
        virtual void clearList() = 0;

        virtual std::map<std::string, Unit*>& getList() const = 0;
};

#endif //IOBSERVER_HPP
