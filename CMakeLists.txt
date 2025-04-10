cmake_minimum_required(VERSION 3.22)
project(i3_widgets_toolkit)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES src/*.cpp)

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/lib/config_parser/include)

add_definitions(-D__CONFIG_PARSER_TEST__=1)
add_definitions(-DCONFIG_FILE="${CMAKE_SOURCE_DIR}/lib/config_parser/tests/test_config.txt")
add_definitions(-DCONFIG_FILE_WITH_SPACES="${CMAKE_SOURCE_DIR}/lib/config_parser/tests/test_config_with_whitespaces.txt")
add_definitions(-DEMPTY_CONFIG_FILE="${CMAKE_SOURCE_DIR}/lib/config_parser/tests/empty_config.txt")
add_definitions(-DCONFIG_FILE_WITH_COMMENTS="${CMAKE_SOURCE_DIR}/lib/config_parser/tests/test_config_with_comments.txt")

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/config_parser)
add_executable(i3_widgets_toolkit ${SOURCES})

target_link_libraries(i3_widgets_toolkit PRIVATE config_parser)
