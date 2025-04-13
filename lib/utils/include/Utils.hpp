#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <exception>
#include <iostream>

#define EMPTY_STRING "Error, string is empty"
#define DELIMITER_NOT_FOUND "Error, delimiter not found"

namespace utils {
  class Utils {
    public:

      class UtilsException : public std::exception {
        public:
          UtilsException(const std::string &message) : message(message) {}
          const char* what() const noexcept override {
            return message.c_str();
          }
        private:
          std::string message;
      };

      static std::vector<std::string> split(const std::string &s, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);

        if (s.empty())
          throw UtilsException(EMPTY_STRING);

        if (s.find(delimiter) == std::string::npos)
          throw UtilsException(DELIMITER_NOT_FOUND);

        while (std::getline(tokenStream, token, delimiter))
          tokens.push_back(token);
        return tokens;
      }
  };
}
