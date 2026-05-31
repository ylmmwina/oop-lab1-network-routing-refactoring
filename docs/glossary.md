# Glossary

## 1. Purpose of the Glossary

This glossary describes the main terms used in the network routing simulator project.

The project models a simplified computer network where devices are connected with links, and packets are transmitted between devices using routing algorithms.

## 2. Domain Terms

### Network

A network is a set of connected devices that can exchange packets with each other.

In this project, the network is represented as a graph where devices are nodes and links are edges.

### Network Topology

Network topology is the structure of connections between network devices.

In the simulator, topology defines which devices are connected and what cost or weight each connection has.

### Device

A device is a general network element that can participate in communication.

In this project, `Device` is the base abstraction for more specific device types such as routers, switches, and hosts.

### Router

A router is a network device responsible for forwarding packets between different parts of a network.

In this project, routers are important for path calculation and packet routing.

### Switch

A switch is a network device used to connect devices within the same local network segment.

In the simulator, a switch is represented as a specific type of network device.

### Host

A host is an end device in the network.

A host can be a source or destination of a packet.

### Link

A link is a connection between two devices.

In the graph representation, a link corresponds to an edge between two nodes.

### Link Weight

A link weight is a numeric value that represents the cost of sending data through a link.

The routing algorithm uses link weights to choose the best path.

### Packet

A packet is a unit of data transmitted through the network.

In this project, a packet has a source device, a destination device, and may have a current state during routing.

### Source Device

A source device is the device from which a packet starts its route.

### Destination Device

A destination device is the device that should receive the packet.

### Route

A route is an ordered sequence of devices or graph nodes used to send a packet from the source to the destination.

### Shortest Path

The shortest path is the route with the minimum total cost between two devices.

In this project, shortest path calculation is based on graph algorithms.

### Routing

Routing is the process of selecting a path for a packet in the network.

### Routing Algorithm

A routing algorithm is an algorithm that calculates a route between two devices.

In the project, routing algorithms are represented through an abstraction so that different algorithms can be used.

### Dijkstra's Algorithm

Dijkstra's algorithm is a graph algorithm used to find the shortest path from one node to other nodes in a weighted graph with non-negative edge weights.

In the simulator, it is used to find an efficient route between network devices.

### Graph

A graph is a mathematical structure consisting of nodes and edges.

In this project, a graph is used to represent the network topology.

### Node

A node is a vertex of a graph.

In the network simulator, a node usually represents a network device.

### Edge

An edge is a connection between two graph nodes.

In the network simulator, an edge represents a network link.

### Weighted Graph

A weighted graph is a graph where each edge has a numeric weight.

The simulator uses weights to represent the cost of links.

### Path

A path is a sequence of connected nodes in a graph.

In the network domain, a path corresponds to a possible route between devices.

### Graph Traversal

Graph traversal is the process of visiting nodes in a graph.

The project may use traversal algorithms such as BFS or DFS.

### BFS

BFS, or Breadth-First Search, is a graph traversal algorithm that visits nodes level by level.

### DFS

DFS, or Depth-First Search, is a graph traversal algorithm that explores a path as deeply as possible before backtracking.

## 3. Software Design Terms

### Class

A class is a blueprint for creating objects.

In this project, classes are used to model devices, packets, graphs, routing algorithms, and the simulator.

### Object

An object is an instance of a class.

For example, a specific router in the simulated network is an object of the `Router` class.

### Encapsulation

Encapsulation is an object-oriented programming principle where internal data is hidden inside a class and accessed through public methods.

The project uses encapsulation to protect internal graph and network data.

### Inheritance

Inheritance is an object-oriented programming mechanism where one class extends another class.

In this project, specific device types inherit from the general `Device` abstraction.

### Polymorphism

Polymorphism allows objects of different classes to be used through a common interface.

In the simulator, routing algorithms can be used through a common `RoutingAlgorithm` interface.

### Abstraction

Abstraction means representing only the essential features of an object or concept while hiding unnecessary implementation details.

The project uses abstraction for devices, graphs, and routing algorithms.

### Interface

An interface defines a set of operations that a class must provide.

In C++, an interface is usually represented by an abstract class with virtual methods.

### Component

A component is a modular part of the system with a clearly defined responsibility.

After refactoring, the project should contain a separate core component with reusable network simulation logic.

### Module

A module is a logically separated part of a program.

Examples of planned modules are graph, model, routing, simulator, and input/output.

### Responsibility

Responsibility is the purpose or task assigned to a class, module, or component.

A good design gives each class a clear and limited responsibility.

### Coupling

Coupling describes how strongly one part of the system depends on another.

Lower coupling usually makes a system easier to maintain and extend.

### Cohesion

Cohesion describes how closely the responsibilities inside one module or class are related.

High cohesion usually means that a class or module has a clear purpose.

### Refactoring

Refactoring is the process of improving the internal structure of code without changing its external behavior.

This laboratory work focuses on refactoring the original network simulator.

### Unit Test

A unit test is an automated test that checks a small part of the program, usually one class or function.

Unit tests are used to verify that refactoring does not break existing behavior.

### Regression Testing

Regression testing is testing performed after changes to ensure that previously working functionality still works correctly.

### Documentation

Documentation is written information that explains how the system works.

In this project, documentation includes Markdown reports, UML diagrams, and generated Doxygen documentation.

### UML

UML, or Unified Modeling Language, is a visual modeling language used to describe software systems.

In this laboratory work, UML diagrams are used to describe the structure, behavior, and deployment of the simulator.

## 4. UML Terms Used in This Project

### Use Case Diagram

A Use Case diagram describes how external users or actors interact with the system.

For this project, it will show actions such as creating a topology, sending a packet, calculating a route, and viewing the result.

### Class Diagram

A Class diagram describes classes, attributes, methods, and relationships between classes.

For this project, it will describe the structure of the graph, devices, packets, routing algorithms, and simulator.

### Component Diagram

A Component diagram shows the main software components and dependencies between them.

For the refactored project, it will show the core library, console application, tests, and documentation generation.

### Package Diagram

A Package diagram shows logical grouping of classes and modules.

For this project, packages may include graph, model, routing, simulator, and io.

### Sequence Diagram

A Sequence diagram shows interactions between objects over time.

For this project, it will describe the process of sending a packet and calculating a route.

### Activity Diagram

An Activity diagram shows a workflow or algorithm as a sequence of actions and decisions.

For this project, it will describe the routing process.

### State Diagram

A State diagram shows possible states of an object and transitions between them.

For this project, it will describe the lifecycle of a packet.

### Object Diagram

An Object diagram shows example objects and links between them at a specific moment.

For this project, it will show an example network topology with several devices and links.

### Deployment Diagram

A Deployment diagram shows how software artifacts are deployed on hardware or execution environments.

For this project, it will show the developer machine, build environment, executable application, tests, and generated documentation.

## 5. Abbreviations

| Abbreviation | Meaning                           |
| ------------ | --------------------------------- |
| UML          | Unified Modeling Language         |
| OOP          | Object-Oriented Programming       |
| BFS          | Breadth-First Search              |
| DFS          | Depth-First Search                |
| CI           | Continuous Integration            |
| CLI          | Command-Line Interface            |
| API          | Application Programming Interface |
| LOC          | Lines of Code                     |
