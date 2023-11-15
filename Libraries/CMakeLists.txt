cmake_minimum_required(VERSION 3.0.0)
project(UIFramework VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB SRC_FILES *.cpp)

add_library(CustomTypes CustomTypes.cpp)
add_library(UIFramework UIFramework.cpp)

target_link_libraries( UIFramework CustomTypes )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
