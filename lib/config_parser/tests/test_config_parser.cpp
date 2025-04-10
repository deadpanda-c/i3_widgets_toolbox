#include "ConfigParser.hpp"
#include <gtest/gtest.h>

#ifndef __CONFIG_PARSER_TEST__
#define CONFIG_FILE "../../tests/test_config.txt"
#define CONFIG_FILE_WITH_SPACES "../../tests/test_config_with_whitespaces.txt"
#define EMPTY_CONFIG_FILE "../../tests/test_empty_config.txt"
#define CONFIG_FILE_WITH_COMMENTS "../../tests/test_config_with_comments.txt"
#endif

TEST(ConfigParserTest, ParseConfigFile)
{
  std::string key = "key";
  std::string value = "value";

  ConfigParser parser;

  parser.loadConfig(CONFIG_FILE);
  std::string parsedValue = parser.get<std::string>(key);

  EXPECT_EQ(parsedValue, value) << "Parsed value does not match expected value.";
}

TEST(ConfigParserTest, ParseConfigFileWithSpaces)
{
  std::string key = "helloworld";
  std::string value = "helloworld";

  ConfigParser parser;

  parser.loadConfig(CONFIG_FILE_WITH_SPACES);
  std::string parsedValue = parser.get<std::string>(key);

  EXPECT_EQ(parsedValue, value) << "Parsed value does not match expected value.";
}

TEST(ConfigParserTest, EmptyConfigFile)
{
  ConfigParser parser;

  // Attempt to load an empty config file
  EXPECT_THROW(parser.loadConfig(EMPTY_CONFIG_FILE), ConfigParser::ConfigParserException) << "Expected runtime error when loading an empty config file.";
}

TEST(ConfigParserTest, InvalidKey)
{
  ConfigParser parser;

  parser.loadConfig(CONFIG_FILE);

  // Attempt to load a config file with an invalid key
  EXPECT_THROW(parser.get<int>("invalid_key"), ConfigParser::ConfigParserException) << "Expected runtime error when accessing an invalid key.";
}

TEST(ConfigParserTest, ConfigWithComments)
{
  ConfigParser parser;

  std::string key = "hello";
  std::string value = "world";

  parser.loadConfig(CONFIG_FILE_WITH_COMMENTS);
  std::string parsedValue = parser.get<std::string>(key);

  EXPECT_EQ(parsedValue, value) << "Parsed value does not match expected value.";
}

