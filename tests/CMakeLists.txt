cmake_minimum_required(VERSION 3.14)
project(oop_lab_tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# GoogleTest is stored as a third-party dependency in the project repository.
add_subdirectory(../third_party/googletest googletest-build)

# Unit test executable.
add_executable(tests_runner
        test_network.cpp
)

# Tests use the same reusable core library as the main application.
target_link_libraries(tests_runner PRIVATE
        network_core
        gtest
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests_runner)