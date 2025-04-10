#pragma once

#include <iostream>
#include <memory>

#include "Observer.hpp"
#include "Publisher.hpp"

class ConcreteObserver : public Observer {
  public:
    ConcreteObserver();
    virtual ~ConcreteObserver() {};

    void update(const std::string &message);

  private:
};
