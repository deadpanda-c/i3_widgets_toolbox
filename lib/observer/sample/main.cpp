#include <iostream>
#include <memory>
#include "Observer.hpp"
#include "ConcreteObserver.hpp"
#include "Publisher.hpp"

int main(void)
{
  Publisher publisher;

  std::shared_ptr<ConcreteObserver> observer1 = std::make_shared<ConcreteObserver>();
  std::shared_ptr<ConcreteObserver> observer2 = std::make_shared<ConcreteObserver>();

  publisher.registerObserver(observer1);
  publisher.registerObserver(observer2);

  publisher.notifyObserver();

  publisher.unregisterObserver(observer1);

  publisher.notifyObserver();
  // Clean up
  publisher.unregisterObserver(observer2);

  return 0;
}
