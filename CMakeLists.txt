cmake_minimum_required(VERSION 3.29)
project(oop_lab1_network_routing_refactoring)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main application executable.
add_executable(network_app
        app/main.cpp
        Graph.h
        GraphAlgorithms.h
        Network.h
        NetworkSimulator.h
)

# Allow files from app/ to include headers from the project root.
target_include_directories(network_app PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Unit tests.
add_subdirectory(tests)