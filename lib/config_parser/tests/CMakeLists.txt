cmake_minimum_required(VERSION 3.22)
project(config_parser_unit_test)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE TEST_SOURCES
    *.cpp
)

add_executable(config_parser_unit_test ${TEST_SOURCES})

target_include_directories(config_parser_unit_test
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    /usr/include/gtest
)

target_link_libraries(config_parser_unit_test
    PRIVATE
        config_parser
        gtest
        gtest_main
        pthread
)

enable_testing()
add_test(NAME config_parser_unit_test
    COMMAND config_parser_unit_test
)
