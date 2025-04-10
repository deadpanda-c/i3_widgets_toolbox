#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

class Observer {
  public:
    virtual ~Observer() = default;
    virtual void update(const std::string& message) = 0;
  private:
    // Prevent copying
    Observer(const Observer&) = delete;
    Observer& operator=(const Observer&) = delete;
};
