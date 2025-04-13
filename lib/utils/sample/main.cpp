#include "Utils.hpp"

int main(void)
{
  std::string str = "Hello World";

  std::vector<std::string> result = utils::Utils::split(str, ' ');

  for (const auto& s : result) {
    std::cout << s << std::endl;
  }
  return 0;
}
