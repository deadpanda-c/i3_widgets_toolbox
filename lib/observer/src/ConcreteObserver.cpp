#include "ConcreteObserver.hpp"

ConcreteObserver::ConcreteObserver() : Observer()
{
  std::cout << "ConcreteObserver created" << std::endl;
}

void ConcreteObserver::update(const std::string &message)
{
  std::cout << "ConcreteObserver received update: " << message << std::endl;
}
