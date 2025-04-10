#pragma once

#include <iostream>
#include <list>
#include <memory>

#include "Observer.hpp"

class Publisher {
  public:
    Publisher() = default;
    virtual ~Publisher() = default;

    void registerObserver(std::shared_ptr<Observer> observer);
    void unregisterObserver(std::shared_ptr<Observer> observer);
    void notifyObserver();
  private:
    std::list<std::shared_ptr<Observer>> _observers;
};
