# Refactoring Plan

## 1. Project Selected for Refactoring

For this laboratory work, the selected project is a C++ network routing simulator originally implemented as a first-semester programming laboratory work.

The project models a simplified computer network. It contains devices such as routers, switches, and hosts, links between them, packets, a graph-based representation of the network topology, and routing algorithms used to find paths between devices.

The original version of the project is preserved in the repository history and marked with the Git tag:

```text
before-refactoring
```

This tag represents the state of the code before any changes made for the Object-Oriented Design laboratory work.

## 2. Main Functionality of the Original Project

The original project provides the following functionality:

* representation of a network as a graph;
* creation of network devices;
* creation of links between devices;
* representation of packets sent through the network;
* implementation of graph traversal algorithms;
* implementation of Dijkstra's shortest path algorithm;
* simulation of packet routing between devices;
* basic unit tests for selected parts of the system.

The project already uses several object-oriented programming concepts:

* encapsulation of graph, network, device, and packet data;
* inheritance in the device hierarchy;
* polymorphism in routing algorithm abstraction;
* templates for generic graph implementation;
* separation of basic domain entities into classes.

## 3. Problems Identified in the Original Design

Although the original implementation is functional, it has several design and maintainability problems.

### 3.1. Weak Separation into Components

Most parts of the system are implemented as header files in the root directory. The project does not have a clear separation between graph logic, network domain model, routing algorithms, simulation logic, application code, and tests.

This makes the system harder to understand, extend, and maintain.

### 3.2. Manual Memory Management

The original implementation uses raw pointers for storing dynamically created devices. This increases the risk of memory leaks, dangling pointers, and unclear ownership.

A safer approach is to use modern C++ smart pointers, especially `std::unique_ptr`, when the simulator owns created devices.

### 3.3. Mixed Responsibilities

Some classes are responsible for more than one concern. For example, the simulator may combine device management, topology management, routing logic, and output formatting.

This violates the Single Responsibility Principle and makes future changes more difficult.

### 3.4. Limited Extensibility

The project contains a routing algorithm abstraction, but the structure can be improved to make it easier to add alternative algorithms or different strategies of routing.

The system should be refactored so that new routing algorithms can be added without changing the simulator logic.

### 3.5. Insufficient Documentation

The original code has limited formal documentation. For the current laboratory work, code documentation will be added using Doxygen comments, and generated documentation will be prepared for publication through GitHub Pages.

### 3.6. Limited Architectural Description

The original project does not contain UML diagrams or a glossary of the problem domain. For this laboratory work, UML models will be created to describe both the current system and the proposed refactored design.

## 4. Goals of Refactoring

The main goal of refactoring is to improve the object-oriented design of the project without changing its core behavior.

The refactoring will focus on:

* clearer separation of responsibilities;
* better project structure;
* extraction of reusable components;
* safer memory management;
* improved testability;
* improved extensibility of routing algorithms;
* better documentation;
* UML-based explanation of the system architecture.

## 5. Planned Architectural Changes

### 5.1. Project Structure Reorganization

The project will be reorganized into separate folders:

```text
include/
src/
app/
tests/
docs/
```

The `include/` directory will contain public headers.
The `src/` directory will contain implementation files.
The `app/` directory will contain the console application entry point.
The `tests/` directory will contain unit tests.
The `docs/` directory will contain documentation, UML diagrams, metrics, and reports.

### 5.2. Component Extraction

The main logic will be extracted into a separate library target, for example:

```text
network_core
```

The console application will use this library. Unit tests will also be linked with this library.

This will make the system closer to a component-based architecture and will allow the same core logic to be reused by different applications.

### 5.3. Improved Memory Ownership

Raw owning pointers will be replaced with smart pointers where appropriate.

For example, if `NetworkSimulator` owns created devices, they should be stored as:

```cpp
std::unique_ptr<Device>
```

This will make object ownership explicit and reduce the risk of memory management errors.

### 5.4. Routing Strategy Improvement

The routing algorithm abstraction will be preserved and improved. The simulator should depend on the abstract `RoutingAlgorithm` interface rather than a concrete implementation.

This follows the Dependency Inversion Principle and makes it easier to add new routing algorithms in the future.

### 5.5. Documentation with Doxygen

Public classes and important methods will be documented using Doxygen comments.

A `Doxyfile` configuration file will be added. The generated documentation should describe the main classes, methods, inheritance relationships, and responsibilities.

### 5.6. UML Models

UML diagrams will be created to explain the system from different points of view.

The following diagrams are planned:

* Use Case diagram;
* Class diagram for the original version;
* Class diagram for the refactored version;
* Component diagram;
* Package diagram;
* Sequence diagram for packet routing;
* Activity diagram for route calculation;
* State diagram for packet lifecycle;
* Object diagram for an example network;
* Deployment diagram;
* optionally, Communication or Composite Structure diagrams for additional detail.

Both PlantUML source files and generated image files will be stored in the repository.

## 6. Planned Unit Tests

Unit tests will be used to verify that refactoring does not break existing functionality.

The following test groups are planned:

* graph creation tests;
* edge and node management tests;
* graph traversal tests;
* Dijkstra shortest path tests;
* network device tests;
* packet creation and state tests;
* network simulator routing tests;
* error handling tests for invalid routes or missing devices.

The same or equivalent tests should pass before and after refactoring.

## 7. Planned Metrics for Comparison

The original and refactored versions will be compared using several metrics.

Planned metrics:

* number of source files;
* number of classes;
* approximate lines of code;
* number of unit tests;
* test pass rate;
* build success;
* separation into CMake targets;
* presence of documentation;
* presence of UML diagrams;
* qualitative analysis of coupling and cohesion.

If possible, additional automated tools may be used to measure code size, complexity, and documentation coverage.

## 8. Expected Result

After refactoring, the project should have a clearer architecture and better object-oriented design.

Expected improvements:

* the core logic is separated from the console application;
* classes have clearer responsibilities;
* ownership of dynamically created objects is explicit;
* routing algorithms can be extended more easily;
* the project has unit tests for important behavior;
* the project has UML diagrams and a glossary;
* the project has generated code documentation;
* the design is easier to understand, maintain, and extend.

The refactoring should preserve the main behavior of the original project. Any behavioral changes must be intentional and documented.
