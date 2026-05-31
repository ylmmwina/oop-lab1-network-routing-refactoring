# Testing Plan

## 1. Purpose of Testing

The purpose of testing in this laboratory work is to verify that the network routing simulator works correctly before and after refactoring.

The refactoring should improve the internal structure of the code without unintentionally changing the main behavior of the program.

Unit tests are used as regression tests. They help confirm that existing functionality continues to work after architectural changes.

## 2. Testing Framework

The project uses GoogleTest as the unit testing framework.

GoogleTest is used to write automated tests for graph operations, routing algorithms, network devices, packets, and the network simulator.

## 3. Current Testing State

The original project already contains a test directory:

```text
tests/
```

The initial version includes tests for selected parts of the project. These tests will be preserved and expanded during the laboratory work.

The current tests are treated as a baseline for checking whether refactoring changes the behavior of the system.

## 4. Testing Goals

The main testing goals are:

* verify graph creation and modification;
* verify adding nodes and edges;
* verify graph traversal algorithms;
* verify shortest path calculation;
* verify correct behavior of network devices;
* verify packet creation and routing;
* verify simulator behavior for valid routes;
* verify simulator behavior for invalid or missing routes;
* verify that refactoring does not break existing functionality.

## 5. Planned Test Groups

### 5.1. Graph Tests

Graph tests should verify the basic graph functionality.

Planned checks:

* graph can be created;
* nodes can be added;
* edges can be added;
* edge weights are stored correctly;
* adjacency information is returned correctly;
* graph handles missing nodes correctly;
* graph does not create unexpected duplicate connections.

Possible test file:

```text
tests/test_graph.cpp
```

### 5.2. Graph Algorithm Tests

Graph algorithm tests should verify traversal and pathfinding algorithms.

Planned checks:

* BFS visits reachable nodes;
* DFS visits reachable nodes;
* Dijkstra returns the shortest path;
* Dijkstra handles disconnected nodes;
* Dijkstra handles the case where source and destination are the same;
* Dijkstra chooses the route with the minimum total weight, not simply the smallest number of edges.

Possible test files:

```text
tests/test_graph_algorithms.cpp
tests/test_dijkstra.cpp
```

### 5.3. Device Tests

Device tests should verify the behavior of network device classes.

Planned checks:

* a router can be created;
* a switch can be created;
* a host can be created;
* every device has a valid identifier or name;
* device type is returned correctly;
* polymorphic use through the base `Device` abstraction works correctly.

Possible test file:

```text
tests/test_devices.cpp
```

### 5.4. Packet Tests

Packet tests should verify packet-related behavior.

Planned checks:

* a packet can be created with source and destination;
* source is stored correctly;
* destination is stored correctly;
* packet data or payload is stored correctly, if supported by the implementation;
* packet state changes correctly during routing, if packet states are implemented.

Possible test file:

```text
tests/test_packet.cpp
```

### 5.5. Routing Algorithm Interface Tests

Routing algorithm tests should verify that routing is performed through an abstraction.

Planned checks:

* routing algorithm can be used through the base `RoutingAlgorithm` interface;
* `DijkstraRouting` calculates the expected route;
* the simulator does not need to know the exact concrete routing algorithm implementation;
* alternative routing algorithms can be added without changing simulator logic.

Possible test file:

```text
tests/test_routing_algorithm.cpp
```

### 5.6. Network Simulator Tests

Network simulator tests should verify the behavior of the full system.

Planned checks:

* simulator can add devices;
* simulator can connect devices;
* simulator can calculate a route between connected devices;
* simulator can send a packet from source to destination;
* simulator handles missing source device;
* simulator handles missing destination device;
* simulator handles disconnected network parts;
* simulator returns or reports route information correctly.

Possible test file:

```text
tests/test_network_simulator.cpp
```

### 5.7. Input and Output Tests

If topology import or export is implemented during refactoring, additional tests should be added.

Planned checks:

* topology can be saved;
* topology can be loaded;
* loaded topology matches the original topology;
* invalid topology data is handled safely.

Possible test file:

```text
tests/test_topology_io.cpp
```

## 6. Regression Testing Approach

Before major refactoring steps, the existing tests should be run and the result should be recorded.

After each important refactoring step, the tests should be run again.

The expected result is:

```text
all tests passed
```

If a test fails after refactoring, the failure must be analyzed. The code should be fixed unless the behavior change was intentional and documented.

## 7. How to Run Tests

The project is built with CMake.

Typical commands for building and running tests:

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
ctest --test-dir cmake-build-debug --output-on-failure
```

In CLion, tests can also be run directly from the IDE using the test configuration generated by CMake.

## 8. Testing During Refactoring

The testing process during refactoring will follow these steps:

1. Run existing tests before changing code.
2. Record the initial test result.
3. Make one small refactoring change.
4. Run tests again.
5. Fix problems if tests fail.
6. Commit the change only after tests pass.
7. Repeat the process for the next change.

This approach reduces the risk of introducing hidden defects.

## 9. Planned Test Result Documentation

Test results will be documented in the laboratory report or in the metrics file.

The documentation should include:

* date of testing;
* tested version or commit;
* command used to run tests;
* number of executed tests;
* number of passed tests;
* number of failed tests;
* short explanation of failures, if any.

Example format:

| Version            | Command                                                  | Passed | Failed | Notes           |
| ------------------ | -------------------------------------------------------- | -----: | -----: | --------------- |
| Before refactoring | `ctest --test-dir cmake-build-debug --output-on-failure` |    TBD |    TBD | Baseline result |
| After refactoring  | `ctest --test-dir cmake-build-debug --output-on-failure` |    TBD |    TBD | Final result    |

## 10. Expected Result

The final version of the project should have a stronger and more complete set of unit tests than the original version.

The tests should demonstrate that:

* the graph implementation works correctly;
* routing algorithms calculate correct paths;
* network devices are modeled correctly;
* packet routing works correctly;
* the refactored architecture preserves the expected behavior of the original project.
