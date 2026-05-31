cmake_minimum_required(VERSION 3.29)
project(oop_lab1_network_routing_refactoring)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Core library with reusable network simulation logic.
add_library(network_core INTERFACE)

target_sources(network_core INTERFACE
        Graph.h
        GraphAlgorithms.h
        Network.h
        NetworkSimulator.h
)

target_include_directories(network_core INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Main application executable.
add_executable(network_app
        app/main.cpp
)

target_link_libraries(network_app PRIVATE
        network_core
)

# Unit tests.
add_subdirectory(tests)