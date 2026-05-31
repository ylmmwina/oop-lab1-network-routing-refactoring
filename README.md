# Network Routing Simulator — OOP Refactoring and UML Modeling

## Overview

This repository contains Laboratory Work 1 for the Object-Oriented Design course.

The project is based on an earlier C++ network routing simulator and was refactored to improve its object-oriented design, project structure, testability, documentation, and UML modeling.

The simulator models a simplified computer network with routers, switches, hosts, links, packets, graph-based topology, and routing algorithms.

## Laboratory Work Goal

The main goal of this work is to analyze an existing project, describe it using UML diagrams, propose design improvements, implement refactoring, verify the behavior with unit tests, and compare the original and refactored versions.

The original version of the project is preserved in Git history and marked with the tag:

```text
before-refactoring
```

## Main Refactoring Changes

The following refactoring changes were implemented:

- the application entry point was moved to `app/main.cpp`;
- public headers were moved to the `include/network/` directory;
- reusable core logic was extracted into the `network_core` CMake interface library;
- unit tests were linked with the same `network_core` library as the main application;
- raw owning pointers in `NetworkSimulator` were replaced with `std::unique_ptr<Device>`;
- simulator query methods `hasDevice()` and `deviceCount()` were added;
- additional unit tests were added for device registry behavior and error handling;
- UML diagrams and generated images were added;
- Doxygen configuration was added for code documentation.

## Project Structure

```text
.
├── app/
│   └── main.cpp
├── docs/
│   ├── architecture-analysis.md
│   ├── glossary.md
│   ├── metrics.md
│   ├── refactoring-plan.md
│   ├── testing.md
│   ├── doxygen/
│   └── uml/
│       ├── README.md
│       ├── source/
│       └── images/
├── include/
│   └── network/
│       ├── graph/
│       ├── model/
│       └── simulator/
├── tests/
│   ├── CMakeLists.txt
│   └── test_network.cpp
├── third_party/
│   └── googletest/
├── CMakeLists.txt
├── Doxyfile
└── README.md
```

## Main Components

### network_core

`network_core` is a reusable CMake interface library that contains the main logic of the project:

- graph representation;
- graph algorithms;
- network domain model;
- routing algorithm abstraction;
- network simulator.

### network_app

`network_app` is the console application that uses `network_core`.

### tests_runner

`tests_runner` contains GoogleTest-based unit tests for the core functionality.

## UML Diagrams

UML source files are stored in:

```text
docs/uml/source/
```

Generated UML images are stored in:

```text
docs/uml/images/
```

The project contains diagrams for:

- Use Case;
- Class diagram before refactoring;
- Class diagram after refactoring;
- Component diagram;
- Package diagram;
- Sequence diagram;
- Activity diagram;
- State diagram;
- Object diagram;
- Deployment diagram.

## Documentation

Project documentation is stored in the `docs/` directory.

Important files:

| File | Description |
|---|---|
| `docs/glossary.md` | Glossary of the network routing domain |
| `docs/refactoring-plan.md` | Planned refactoring steps and goals |
| `docs/testing.md` | Testing strategy |
| `docs/architecture-analysis.md` | Object-oriented design and architecture analysis |
| `docs/metrics.md` | Metrics and comparison plan |
| `docs/uml/README.md` | Description of UML diagram structure |

## Build

The project is built with CMake and C++20.

In CLion, open the project directory and use:

```text
Reload CMake Project
Build Project
```

The main executable target is:

```text
network_app
```

## Tests

The project uses GoogleTest.

The test target is:

```text
tests_runner
```

Tests cover:

- class hierarchy and polymorphism;
- graph and Dijkstra shortest path behavior;
- device registry behavior in `NetworkSimulator`;
- packet sending flow;
- error handling for invalid simulator operations.

## Refactoring Summary

The original project was functional but had several design limitations:

- application code and core logic were not clearly separated;
- headers were located in the repository root;
- simulator device ownership was represented with raw pointers;
- tests were not connected through a reusable core component;
- UML diagrams and generated documentation were missing.

The refactored version improves:

- separation of concerns;
- memory ownership safety;
- component structure;
- testability;
- maintainability;
- UML-based architecture description.

## Technologies Used

- C++20;
- CMake;
- CLion;
- GoogleTest;
- PlantUML;
- Doxygen;
- Git and GitHub.