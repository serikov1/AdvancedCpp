cmake_minimum_required(VERSION 3.24)
project(gtestTraining)

set(CMAKE_CXX_STANDARD 14)

add_executable(gtestTraining main.cpp)
target_link_libraries(gtestTraining gtest gmock pthread)