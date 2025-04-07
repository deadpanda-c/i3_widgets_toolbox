#include "ConfigParser.hpp"

int main(void)
{
  std::string key = "helloworld";
  ConfigParser configParser;

  configParser.loadConfig("../sample/config_with_whitespaces.txt");
  std::string value = configParser.get<std::string>(key);

  if (value.empty()) {
    std::cerr << "Key not found or value is empty." << std::endl;
    return 1;
  }
  std::cout << "Value for key '" << key << "': " << value << std::endl;
  return 0;
}
