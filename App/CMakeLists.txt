cmake_minimum_required(VERSION 3.0.0)
project(ConsoleRenderer VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB SRC_FILES *.cpp)

add_executable(BuiltApp main.cpp)

target_link_libraries( BuiltApp UIFramework )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
