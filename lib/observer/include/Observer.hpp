#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

class Observer {
  public:
    Observer() = default;
    virtual ~Observer() = 0;
    virtual void update(const std::string& message) = 0;

  private:
    // Prevent copying
    Observer(const Observer&) = delete;
    Observer& operator=(const Observer&) = delete;
};
