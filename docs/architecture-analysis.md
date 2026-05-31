# Architecture and Object-Oriented Design Analysis

## 1. Purpose of the Analysis

This document analyzes the architecture and object-oriented design of the network routing simulator.

The analysis focuses on:

* object-oriented programming principles;
* general software design principles;
* SOLID principles;
* coupling and cohesion;
* maintainability and extensibility;
* planned architectural improvements.

The goal is to identify design problems in the original version and explain how the refactored version improves the structure of the project.

## 2. Overview of the Original Architecture

The original project is a C++ network routing simulator.

It contains several main parts:

* graph representation;
* graph algorithms;
* network devices;
* network links;
* packets;
* routing algorithms;
* network simulator;
* console application;
* unit tests.

The main idea of the project is good for object-oriented design because the domain naturally contains objects such as devices, packets, links, routes, and algorithms.

However, the original project structure is still close to a first-semester educational project. The code works, but its architecture can be improved.

## 3. Positive Aspects of the Original Design

### 3.1. Clear Domain Idea

The project has a clear subject area: routing in a computer network.

This makes the design understandable and suitable for UML modeling.

### 3.2. Use of Classes

The project uses classes to represent important domain concepts.

Examples:

* graph;
* device;
* router;
* switch;
* host;
* packet;
* routing algorithm;
* network simulator.

This is a good basis for object-oriented refactoring.

### 3.3. Use of Inheritance

The device hierarchy uses inheritance.

A general device abstraction is extended by more specific device types such as router, switch, and host.

This matches the object-oriented idea of generalization and specialization.

### 3.4. Use of Polymorphism

The routing algorithm abstraction allows the simulator to work with routing algorithms through a common interface.

This is useful because different routing algorithms can be implemented and used without changing the whole system.

### 3.5. Use of Generic Programming

The graph implementation uses templates.

This makes the graph structure reusable for different node and edge types.

## 4. Problems in the Original Architecture

### 4.1. Weak Component Separation

The original project keeps most core files in the root directory.

This makes it harder to understand which files belong to the graph layer, domain model, routing layer, simulator layer, or application layer.

A better structure should separate these responsibilities into folders and CMake targets.

### 4.2. Mixed Responsibilities

Some parts of the program may combine several responsibilities.

For example, the simulator may be responsible for:

* storing devices;
* connecting devices;
* managing topology;
* selecting routes;
* sending packets;
* printing results.

This increases complexity and makes the class harder to test and extend.

### 4.3. Unclear Ownership of Objects

The original version uses raw pointers in some places.

Raw pointers do not clearly show who owns an object and who is responsible for deleting it.

This can lead to:

* memory leaks;
* dangling pointers;
* accidental double deletion;
* unclear object lifetime.

Modern C++ code should use smart pointers where ownership exists.

### 4.4. Limited Modularity

The original project does not clearly separate reusable library code from the console application.

Because of this, the same core logic cannot be easily reused in another application, for example in a GUI application, web service, or separate testing tool.

### 4.5. Limited Documentation

The original code does not contain complete generated documentation.

For a larger project, documentation is important because it explains class responsibilities, method behavior, and relationships between parts of the system.

### 4.6. No UML Model in the Original Repository

The original project does not include UML diagrams.

This makes it harder to understand the architecture without reading the source code directly.

The current laboratory work adds UML models to describe the system structure and behavior.

## 5. Analysis of OOP Principles

### 5.1. Encapsulation

Encapsulation is partially used in the original project.

Classes hide some internal data and provide public methods for working with objects.

However, encapsulation can be improved by:

* reducing direct access to internal containers;
* making ownership rules explicit;
* separating public interfaces from implementation details;
* moving implementation from headers to source files where appropriate.

### 5.2. Inheritance

Inheritance is used in the device hierarchy.

This is appropriate because `Router`, `Switch`, and `Host` can be treated as more specific kinds of `Device`.

However, inheritance should remain simple. It should not be used where composition would be clearer.

### 5.3. Polymorphism

Polymorphism is used for routing algorithms.

This is a strong design decision because the simulator can depend on an abstraction rather than a concrete algorithm.

The refactored version should preserve and improve this idea.

### 5.4. Abstraction

The project uses abstractions for graph and routing logic.

The refactoring should make abstractions more explicit by separating interfaces from concrete implementations where appropriate.

## 6. Analysis of General Design Principles

### 6.1. KISS

KISS means that the design should remain simple.

The original project is relatively simple, which is good.

However, the structure can still be improved without overengineering. The refactoring should not add unnecessary patterns or complicated architecture only for the sake of complexity.

### 6.2. DRY

DRY means avoiding unnecessary duplication.

The original project should be checked for repeated logic in graph operations, routing, and output formatting.

If repeated logic exists, it should be extracted into functions or classes with clear responsibilities.

### 6.3. YAGNI

YAGNI means that unnecessary functionality should not be implemented before it is needed.

The refactoring should focus on real improvements:

* project structure;
* memory safety;
* testability;
* documentation;
* extensibility of routing algorithms.

It should not add unrelated features that do not support the laboratory goal.

### 6.4. Separation of Concerns

The original version has limited separation of concerns.

The refactored version should separate:

* graph data structure;
* network domain model;
* routing algorithms;
* simulation logic;
* console application;
* tests;
* documentation.

This makes the system easier to understand and modify.

### 6.5. Reusability

The graph and routing logic can be reusable.

After refactoring, reusable code should be placed in a separate library target.

This makes it possible to use the same logic from the console application and from unit tests.

### 6.6. Maintainability

Maintainability should improve after refactoring because:

* files will be organized by responsibility;
* class responsibilities will be clearer;
* tests will protect behavior;
* documentation will explain the design;
* UML diagrams will visualize the architecture.

## 7. SOLID Analysis

### 7.1. Single Responsibility Principle

The Single Responsibility Principle states that a class should have one main reason to change.

In the original version, some classes may have too many responsibilities.

Planned improvement:

* keep graph logic inside graph classes;
* keep route calculation inside routing algorithm classes;
* keep simulation coordination inside the simulator;
* keep console input/output inside the application layer;
* keep serialization in a separate input/output module if implemented.

### 7.2. Open/Closed Principle

The Open/Closed Principle states that software entities should be open for extension but closed for modification.

The routing algorithm abstraction supports this principle.

Planned improvement:

* make it possible to add a new routing algorithm without changing `NetworkSimulator`;
* depend on the abstract `RoutingAlgorithm` interface;
* isolate algorithm-specific logic inside concrete classes.

### 7.3. Liskov Substitution Principle

The Liskov Substitution Principle means that objects of derived classes should be usable wherever the base class is expected.

For this project, `Router`, `Switch`, and `Host` should behave correctly when used through a `Device` pointer or reference.

Planned improvement:

* ensure that derived device classes do not break expectations of the base `Device` abstraction;
* avoid putting behavior into `Device` that does not make sense for all device types.

### 7.4. Interface Segregation Principle

The Interface Segregation Principle means that interfaces should not force classes to implement methods they do not need.

Planned improvement:

* keep the routing algorithm interface small;
* avoid large base classes with unrelated methods;
* split interfaces if responsibilities become too broad.

### 7.5. Dependency Inversion Principle

The Dependency Inversion Principle states that high-level modules should depend on abstractions, not concrete implementations.

The simulator should depend on `RoutingAlgorithm`, not directly on `DijkstraRouting`.

Planned improvement:

* inject routing algorithm dependency into the simulator;
* use abstract interfaces for behavior that may vary;
* keep concrete algorithms replaceable.

## 8. Coupling and Cohesion

### 8.1. Coupling

Coupling describes how strongly parts of the system depend on each other.

The original structure has higher coupling because the application, simulator, graph, and routing parts are not clearly separated.

The refactored version should reduce coupling by:

* separating modules into folders;
* introducing a core library;
* using interfaces for routing algorithms;
* avoiding unnecessary dependencies between modules.

### 8.2. Cohesion

Cohesion describes how closely related the responsibilities inside a module are.

The refactored version should increase cohesion by grouping related elements together:

* graph classes in the graph module;
* network domain classes in the model module;
* routing algorithms in the routing module;
* simulation coordination in the simulator module;
* console application code in the app module.

## 9. Law of Demeter

The Law of Demeter recommends that an object should not depend too deeply on the internal structure of other objects.

The refactoring should avoid code where one object accesses a chain of internal objects from another object.

Instead, classes should provide clear methods that hide internal details.

Example improvement:

* external code should ask the simulator to calculate a route instead of directly manipulating all internal graph structures.

## 10. Principle of Least Astonishment

The Principle of Least Astonishment means that code should behave in a way that is expected by developers.

The refactored version should improve this principle by:

* using clear class and method names;
* using predictable ownership rules;
* using standard C++ smart pointers;
* organizing files according to responsibilities;
* documenting non-obvious behavior.

## 11. Planned Design Patterns

### 11.1. Strategy Pattern

The routing algorithm abstraction corresponds to the Strategy pattern.

The simulator can use different routing strategies through a common interface.

Example:

* `RoutingAlgorithm` is the strategy interface;
* `DijkstraRouting` is a concrete strategy;
* `NetworkSimulator` is the context that uses the strategy.

This pattern is appropriate because route calculation may vary independently from the simulator.

### 11.2. Template Method or Factory Pattern

These patterns are not required at the beginning of refactoring.

They may be considered only if the project needs them naturally.

For example, a factory may be useful if device creation becomes more complex, but it should not be added without a real reason.

## 12. Expected Improvements After Refactoring

The refactored project should improve the design in the following ways:

| Aspect             | Original Version            | Refactored Version                                      |
| ------------------ | --------------------------- | ------------------------------------------------------- |
| Project structure  | Mostly root-level headers   | Organized into `include`, `src`, `app`, `tests`, `docs` |
| Components         | No clear reusable library   | Separate `network_core` library                         |
| Memory ownership   | Raw pointers in some places | Smart pointers where ownership exists                   |
| Routing algorithms | Basic abstraction           | Clear Strategy-based design                             |
| Testing            | Existing basic tests        | Expanded regression tests                               |
| Documentation      | Limited                     | Doxygen + Markdown documentation                        |
| UML                | Not included                | UML source files and generated diagrams                 |
| Maintainability    | Acceptable for small lab    | Improved for larger project                             |
| Extensibility      | Limited                     | Easier to add algorithms and modules                    |

## 13. Conclusion

The original project is a good basis for object-oriented design because it has a clear domain model and already uses classes, inheritance, templates, and polymorphism.

The main weakness is not the idea of the project, but the architecture around it: file organization, component separation, memory ownership, documentation, and UML modeling.

The planned refactoring should preserve the behavior of the simulator while making the code safer, clearer, more modular, and easier to extend.

## 14. Implemented Refactoring Changes

This section summarizes the refactoring changes that were actually implemented in the project.

### 14.1. Application Entry Point Separation

The original version kept the application entry point in the repository root as `main.cpp`.

The refactored version moves it to:

```text
app/main.cpp
```

This separates the console application from the reusable project logic.

### 14.2. Public Header Reorganization

The original version stored public headers in the repository root.

The refactored version moves them into the `include/network/` directory:

```text
include/network/graph/
include/network/model/
include/network/simulator/
```

This makes the public API structure clearer and closer to common C++ project organization.

### 14.3. Core Library Extraction

The original executable target directly included the main project headers.

The refactored version introduces a reusable CMake interface library:

```text
network_core
```

The console application target `network_app` and the test target `tests_runner` both use this core library.

This improves modularity and reusability.

### 14.4. Improved Device Ownership

The original `NetworkSimulator` stored devices using raw owning pointers:

```cpp
std::map<std::string, Device*> devices_;
```

The refactored version uses smart pointers:

```cpp
std::map<std::string, std::unique_ptr<Device>> devices_;
```

This change makes ownership explicit and removes the need for manual `delete` calls in the simulator destructor.

As a result, the design is safer and closer to modern C++ practices.

### 14.5. Improved Encapsulation and Testability

The simulator now provides query methods:

```cpp
bool hasDevice(const std::string& name) const;
std::size_t deviceCount() const;
```

These methods allow tests and external code to check simulator state without accessing internal containers directly.

This improves encapsulation and supports unit testing.

### 14.6. Updated Unit Tests

The unit tests were updated to use modern C++ memory management with `std::make_unique`.

Additional tests were added for:

- device registry behavior;
- simulator state queries;
- adding a null device;
- connecting unknown devices.

This improves regression testing and helps verify that refactoring did not break existing behavior.

### 14.7. UML Modeling

UML source files were added to:

```text
docs/uml/source/
```

Generated UML images were added to:

```text
docs/uml/images/
```

The UML model includes both the original and refactored class structure, as well as behavioral and architectural diagrams.

### 14.8. Documentation Support

A `Doxyfile` configuration was added for generating code documentation with Doxygen.

The repository documentation was also expanded with:

- glossary;
- refactoring plan;
- testing plan;
- metrics and comparison plan;
- UML documentation;
- architecture analysis.

## 15. Final Architecture Evaluation

The final architecture is more maintainable than the original version.

The main improvements are:

- better separation of concerns;
- clearer project structure;
- reusable core component;
- safer memory ownership;
- improved testability;
- more complete documentation;
- UML-based explanation of structure and behavior.

The project still remains intentionally simple. It was not overcomplicated with unnecessary frameworks or unrelated features.

This follows the KISS and YAGNI principles while still improving the object-oriented design of the system.