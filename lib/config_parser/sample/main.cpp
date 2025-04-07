#include "ConfigParser.hpp"

int main(void)
{
  std::string key = "KEY";
  ConfigParser configParser("../sample/config.txt");

  std::string value = configParser.get<std::string>(key);

  if (value.empty())
  {
    std::cerr << "Key not found or value is empty." << std::endl;
    return 1;
  }
  std::cout << "Value for key '" << key << "': " << value << std::endl;
  return 0;
}
