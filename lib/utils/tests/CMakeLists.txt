cmake_minimum_required(VERSION 3.22)
project(utils_unit_test)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE TEST_SOURCES
    *.cpp
)

add_executable(utils_unit_test ${TEST_SOURCES})

target_include_directories(utils_unit_test
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    /usr/include/gtest
)

target_link_libraries(utils_unit_test
    PRIVATE
        utils
        gtest
        gtest_main
        pthread
)

enable_testing()
add_test(NAME utils_unit_test
    COMMAND utils_unit_test
)
