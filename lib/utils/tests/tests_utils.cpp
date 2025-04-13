#include <gtest/gtest.h>
#include "Utils.hpp"

TEST(UtilsTest, SplitString) {
  std::string str = "Hello,World,Test";
  std::vector<std::string> expected = {"Hello", "World", "Test"};
  std::vector<std::string> result = utils::Utils::split(str, ',');

  EXPECT_EQ(result, expected);
}

TEST(UtilsTest, SplitEmptyString) {
  std::string str = "";

  EXPECT_THROW({
    try {
      std::vector<std::string> result = utils::Utils::split(str, ',');
    } catch (const utils::Utils::UtilsException& e) {
      EXPECT_STREQ(e.what(), EMPTY_STRING);
      throw;
    }
  }, utils::Utils::UtilsException);

}

TEST(UtilsTest, SplitStringWithWrongDelimiter) {
  std::string str = "Hello,World,Test";
  std::vector<std::string> expected = {"Hello", "World", "Test"};

  EXPECT_THROW({
    try {
      std::vector<std::string> result = utils::Utils::split(str, ' ');
    } catch (const utils::Utils::UtilsException& e) {
      EXPECT_STREQ(e.what(), DELIMITER_NOT_FOUND);
      throw;
    }
  }, utils::Utils::UtilsException);
}
