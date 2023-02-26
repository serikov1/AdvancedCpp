cmake_minimum_required(VERSION 3.24)
project(testStorage)

set(CMAKE_CXX_STANDARD 17)
find_package(fmt)

add_executable(testStorage main.cpp)
add_library(libStorage STATIC ../alignedStorage/library.cpp ../alignedStorage/library.h)

target_link_libraries(testStorage libStorage fmt::fmt)
