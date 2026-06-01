# Network Routing Simulator — OOP Refactoring and UML Modeling

## Overview

This repository contains Laboratory Work 1 for the Object-Oriented Design course.

The project is based on an earlier C++ network routing simulator and was refactored to improve its object-oriented design, project structure, testability, documentation, and UML modeling.

The simulator models a simplified computer network with routers, switches, hosts, links, packets, graph-based topology, and routing algorithms.

## Completed Laboratory Tasks

This repository contains the implementation of the main task and several extra tasks.

| Task | Status | Description |
|---|---|---|
| Lab 1a | Completed | Refactoring and UML modeling of an existing C++ project |
| Lab 1b | Completed | Extra UML domain modeling of GitHub as a code repository service |
| Lab 1c | Not included | Requires peer review of another student's UML model |
| Lab 1d | Completed | Retrospective report about the UML modeling tool |
| Lab 1e | Completed | UML modeling of a non-software real-life process |

## Laboratory Work 1a Goal

The main goal of Lab 1a is to analyze an existing project, describe it using UML diagrams, propose design improvements, implement refactoring, verify the behavior with unit tests, and compare the original and refactored versions.

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
- manual device cleanup with `delete` was removed;
- copy operations for `NetworkSimulator` were disabled because the simulator owns devices;
- move operations for `NetworkSimulator` were allowed;
- simulator query methods `hasDevice()` and `deviceCount()` were added;
- additional unit tests were added for device registry behavior and error handling;
- Doxygen comments were added to the main model, graph, algorithm, and simulator classes;
- UML diagrams and generated images were added;
- Doxygen configuration was added for generated code documentation.

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
│   ├── extra/
│   │   ├── 1b-github-modeling/
│   │   ├── 1d-uml-tool-retrospective.md
│   │   └── 1e-non-software-uml/
│   └── uml/
│       ├── README.md
│       ├── source/
│       └── images/
├── include/
│   └── network/
│       ├── graph/
│       │   ├── Graph.h
│       │   └── GraphAlgorithms.h
│       ├── model/
│       │   └── Network.h
│       └── simulator/
│           └── NetworkSimulator.h
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

### `network_core`

`network_core` is a reusable CMake interface library that contains the main logic of the project:

- graph representation;
- graph algorithms;
- network domain model;
- routing algorithm abstraction;
- network simulator.

### `network_app`

`network_app` is the console application that uses `network_core`.

### `tests_runner`

`tests_runner` contains GoogleTest-based unit tests for the core functionality.

## UML Diagrams for Lab 1a

UML source files are stored in:

```text
docs/uml/source/
```

Generated UML images are stored in:

```text
docs/uml/images/
```

The project contains the following UML diagram types for Lab 1a:

| Diagram Type | Purpose |
|---|---|
| Use Case | Shows main user interactions with the simulator |
| Class Before Refactoring | Shows the original structure and raw pointer ownership |
| Class After Refactoring | Shows the refactored structure and smart pointer ownership |
| Component | Shows main software components after refactoring |
| Package | Shows logical package structure |
| Sequence | Shows packet routing interaction |
| Activity | Shows routing workflow |
| State | Shows packet lifecycle |
| Object | Shows example runtime network objects |
| Deployment | Shows development, build, and documentation environment |
| Communication | Shows object collaboration during packet routing |
| Composite Structure | Shows internal parts of `NetworkSimulator` |
| Timing | Shows packet state and route progress over time |
| Interaction Overview | Shows routing workflow with referenced interactions |

## Extra Task 1b — GitHub Domain Modeling

Extra task 1b is stored in:

```text
docs/extra/1b-github-modeling/
```

This part models GitHub as a code repository hosting service.

It contains:

- domain description;
- glossary;
- PlantUML source files;
- generated PNG images.

Implemented diagram types:

- Use Case;
- Class;
- Sequence;
- Activity;
- State;
- Component.

## Extra Task 1d — UML Tool Retrospective

Extra task 1d is stored in:

```text
docs/extra/1d-uml-tool-retrospective.md
```

This report describes the experience of using PlantUML with the CLion plugin.

It covers:

- why PlantUML was chosen;
- installation and setup;
- documentation quality;
- supported UML diagram types;
- convenience of use;
- positive and negative aspects;
- problems encountered;
- what could be improved in future work.

## Extra Task 1e — UML as a General Modeling Language

Extra task 1e is stored in:

```text
docs/extra/1e-non-software-uml/
```

This part uses UML to describe a non-software real-life process:

```text
Submitting a Laboratory Work Before Deadline
```

It contains:

- README explanation;
- PlantUML source files;
- generated PNG images.

Implemented diagram types:

- Use Case;
- Activity;
- State;
- Sequence.

## Documentation

Project documentation is stored in the `docs/` directory.

Important files:

| File | Description |
|---|---|
| `docs/glossary.md` | Glossary of the network routing domain |
| `docs/refactoring-plan.md` | Planned refactoring steps and goals |
| `docs/testing.md` | Testing strategy and implemented tests |
| `docs/architecture-analysis.md` | Object-oriented design and architecture analysis |
| `docs/metrics.md` | Metrics and comparison plan |
| `docs/uml/README.md` | Description and index of UML diagrams |
| `docs/extra/1d-uml-tool-retrospective.md` | UML tool retrospective |
| `docs/extra/1b-github-modeling/` | Extra GitHub domain model |
| `docs/extra/1e-non-software-uml/` | Extra non-software UML model |

## Code Documentation

The project contains Doxygen comments for the main classes and methods.

Doxygen configuration is stored in:

```text
Doxyfile
```

The configuration is prepared to generate HTML documentation from:

```text
include/
app/
tests/
```

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
- manual cleanup with `delete` was required;
- tests were not connected through a reusable core component;
- UML diagrams and generated documentation were missing.

The refactored version improves:

- separation of concerns;
- memory ownership safety;
- component structure;
- testability;
- maintainability;
- extensibility;
- UML-based architecture description;
- generated documentation readiness.

## Technologies Used

- C++20;
- CMake;
- CLion;
- GoogleTest;
- PlantUML;
- Doxygen;
- Git and GitHub.

## Final Notes

The main implementation and documentation focus on Lab 1a.

Extra tasks 1b, 1d, and 1e are included in the `docs/extra/` directory.

Extra task 1c is not included because it requires access to another student's UML model for peer review.