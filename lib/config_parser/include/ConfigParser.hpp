#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>

// Define macros for error messages
#define KEY_NOT_FOUND(key) "Key not found: " + key
#define INVALID_KEY(key) "Invalid key: " + key
#define FILE_NOT_FOUND(filename) "File not found: " + filename
#define EMPTY_FILE(filename) "Empty filename: " + filename
#define INVALID_CONFIG_FORMAT(filename) "Invalid config format in file: " + filename

class ConfigParser {
  public:
    class ConfigParseException : public std::exception {
      public:
        ConfigParseException(const std::string& message) : msg(message) {}
        virtual const char* what() const noexcept override {
            return msg.c_str();
        }
      private:
        std::string msg;
    };

    // Constructor
    ConfigParser(const std::string& filename);
    ~ConfigParser();

    // Get a value from the config
    template <typename T>
    T get(const std::string& key) const {
      auto it = _configMap.find(key);

      if (it != _configMap.end()) {
        std::istringstream iss(it->second);
        T value;
        iss >> value;

        if (iss.fail())
          throw ConfigParseException(INVALID_KEY(key));
        return value;
      } else {
        throw ConfigParseException(KEY_NOT_FOUND(key));
      }
    }

    // load config from file
    int loadConfig(const std::string &filename);

    private:
    std::unordered_map<std::string, std::string> _configMap;
    std::vector<std::string> _configLines;
    std::string _filename;


};
