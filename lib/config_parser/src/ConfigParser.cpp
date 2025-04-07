#include "ConfigParser.hpp"

ConfigParser::~ConfigParser()
{
    // Destructor
}

int ConfigParser::loadConfig(const std::string &filename)
{
  if (filename.empty())
    throw ConfigParserException(std::string(EMPTY_FILE(filename)));

  _filename = filename;
  std::ifstream file(_filename);
  if (!file.is_open())
    throw ConfigParserException(std::string(FILE_NOT_FOUND(filename)));

  std::string line;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#') {
      continue; // Skip empty lines and comments
    }

    // remove every whitespace
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    size_t pos = line.find('=');
    if (pos == std::string::npos) {
      throw ConfigParserException(std::string(INVALID_CONFIG_FORMAT(filename)));
    }
    std::string key = line.substr(0, pos);
    std::string value = line.substr(pos + 1);
    _configMap[key] = value;
    _configLines.push_back(line);
  }
  if (_configMap.empty())
    throw ConfigParserException(std::string(EMPTY_FILE(filename)));
  file.close();
  return 0;
}

