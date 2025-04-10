#include "Publisher.hpp"

void Publisher::registerObserver(std::shared_ptr<Observer> observer)
{
  _observers.push_back(observer);
}

void Publisher::unregisterObserver(std::shared_ptr<Observer> observer)
{
  _observers.remove(observer);
}

void Publisher::notifyObserver()
{
  for (const auto& observer : _observers)
    observer->update("Hello World");
}
