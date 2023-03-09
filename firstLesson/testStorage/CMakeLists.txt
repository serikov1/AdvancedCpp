cmake_minimum_required(VERSION 3.24)
project(testStorage)
find_package(fmt)

# Here we fetch and include gtest repository
# This approach do not spam into system libs and fetch predictable version of gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG 703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
enable_testing()

add_executable(main main.cpp)
add_library(libStorage STATIC ../alignedStorage/library.cpp ../alignedStorage/library.h)
target_link_libraries(main PRIVATE gtest_main fmt::fmt libStorage)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR})

# Find all tests in test target. Now we can use internal cmake tools to run tests. Also, clion can handle target as a tests.
gtest_discover_tests(main)



