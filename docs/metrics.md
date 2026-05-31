# Metrics and Comparison Plan

## 1. Purpose of Metrics

The purpose of this document is to define and record the metrics used to compare the original and refactored versions of the network routing simulator.

The comparison is needed to evaluate whether the refactoring improved the internal structure of the project without breaking its behavior.

The metrics are divided into:

* structural metrics;
* testing metrics;
* build metrics;
* documentation metrics;
* qualitative design metrics;
* optional performance metrics.

## 2. Compared Versions

The project will be compared in two main states.

| Version            | Description             | Git Reference                   |
| ------------------ | ----------------------- | ------------------------------- |
| Original version   | Code before refactoring | `before-refactoring`            |
| Refactored version | Code after refactoring  | final commit of laboratory work |

The original version is preserved with the Git tag:

```text
before-refactoring
```

This allows the previous state of the project to be reviewed separately from the refactored implementation.

## 3. Structural Metrics

Structural metrics describe the organization and size of the codebase.

| Metric                                 | Original Version | Refactored Version | Notes                                                |
| -------------------------------------- | ---------------: | -----------------: | ---------------------------------------------------- |
| Number of source/header files          |              TBD |                TBD | Counted manually or with command-line tools          |
| Number of directories with source code |              TBD |                TBD | Shows project organization                           |
| Number of CMake targets                |              TBD |                TBD | Expected to increase after extracting `network_core` |
| Number of classes                      |              TBD |                TBD | Counted from core model and algorithm classes        |
| Approximate lines of code              |              TBD |                TBD | Can be measured with command-line tools              |
| Number of public headers               |              TBD |                TBD | Shows public API surface                             |
| Number of implementation files         |              TBD |                TBD | Expected to become clearer after refactoring         |

## 4. Testing Metrics

Testing metrics describe the level of automated verification.

| Metric                 | Original Version | Refactored Version | Notes                                |
| ---------------------- | ---------------: | -----------------: | ------------------------------------ |
| Number of test files   |              TBD |                TBD | Expected to increase                 |
| Number of unit tests   |              TBD |                TBD | Counted by GoogleTest output         |
| Passed tests           |              TBD |                TBD | Recorded from test run               |
| Failed tests           |              TBD |                TBD | Should be 0 in the final version     |
| Test framework         |       GoogleTest |         GoogleTest | Same framework before and after      |
| Regression test result |              TBD |                TBD | Shows whether behavior was preserved |

## 5. Build Metrics

Build metrics describe whether the project can be built and executed successfully.

| Metric                     | Original Version | Refactored Version | Notes                             |
| -------------------------- | ---------------- | ------------------ | --------------------------------- |
| CMake configure result     | TBD              | TBD                | Should succeed                    |
| Build result               | TBD              | TBD                | Should succeed                    |
| Test execution result      | TBD              | TBD                | Should succeed                    |
| Main application execution | TBD              | TBD                | Should run without runtime errors |

## 6. Documentation Metrics

Documentation metrics describe the amount and quality of project documentation.

| Metric                       | Original Version | Refactored Version | Notes                               |
| ---------------------------- | ---------------: | -----------------: | ----------------------------------- |
| Markdown documentation files |              TBD |                TBD | Expected to increase                |
| Glossary availability        |     No / Limited |                Yes | Required for the laboratory work    |
| UML source files             |                0 |                TBD | PlantUML files in `docs/uml/source` |
| UML generated images         |                0 |                TBD | PNG/SVG files in `docs/uml/images`  |
| Doxygen configuration        |               No |                TBD | `Doxyfile` should be added          |
| Generated API documentation  |               No |                TBD | Optional GitHub Pages publication   |

## 7. UML Metrics

UML metrics describe the modeling part of the laboratory work.

| Diagram Type             | Planned File                                        | Status   |
| ------------------------ | --------------------------------------------------- | -------- |
| Use Case                 | `docs/uml/source/use-case.puml`                     | Planned  |
| Class Before Refactoring | `docs/uml/source/class-before.puml`                 | Planned  |
| Class After Refactoring  | `docs/uml/source/class-after.puml`                  | Planned  |
| Component                | `docs/uml/source/component-after.puml`              | Planned  |
| Package                  | `docs/uml/source/package-after.puml`                | Planned  |
| Sequence                 | `docs/uml/source/sequence-send-packet.puml`         | Planned  |
| Activity                 | `docs/uml/source/activity-routing.puml`             | Planned  |
| State                    | `docs/uml/source/state-packet.puml`                 | Planned  |
| Object                   | `docs/uml/source/object-demo-network.puml`          | Planned  |
| Deployment               | `docs/uml/source/deployment.puml`                   | Planned  |
| Communication            | `docs/uml/source/communication-routing.puml`        | Optional |
| Composite Structure      | `docs/uml/source/composite-structure-network.puml`  | Optional |
| Timing                   | `docs/uml/source/timing-packet-routing.puml`        | Optional |
| Interaction Overview     | `docs/uml/source/interaction-overview-routing.puml` | Optional |

## 8. Qualitative Design Metrics

Some design aspects cannot be measured only by numbers. They will be evaluated qualitatively.

| Design Aspect                       | Original Version         | Refactored Version | Expected Improvement                 |
| ----------------------------------- | ------------------------ | ------------------ | ------------------------------------ |
| Separation of concerns              | Limited                  | TBD                | Clearer modules                      |
| Coupling                            | Medium / High            | TBD                | Lower coupling                       |
| Cohesion                            | Medium                   | TBD                | Higher cohesion                      |
| Memory ownership clarity            | Limited                  | TBD                | Smart pointers and clearer ownership |
| Extensibility of routing algorithms | Partial                  | TBD                | Improved Strategy-based design       |
| Reusability                         | Limited                  | TBD                | Core library can be reused           |
| Testability                         | Basic                    | TBD                | More focused unit tests              |
| Documentation quality               | Limited                  | TBD                | Markdown, UML, Doxygen               |
| Maintainability                     | Acceptable for small lab | TBD                | Improved structure                   |

## 9. Optional Performance Metrics

Performance metrics may be measured if it is practical for the project.

Possible measurements:

* route calculation time for a small graph;
* route calculation time for a medium graph;
* route calculation time for a larger graph;
* application startup time;
* test execution time.

Example table:

| Scenario                       | Original Version | Refactored Version | Notes                     |
| ------------------------------ | ---------------: | -----------------: | ------------------------- |
| Dijkstra on small topology     |              TBD |                TBD | Measured in milliseconds  |
| Dijkstra on medium topology    |              TBD |                TBD | Measured in milliseconds  |
| Dijkstra on large topology     |              TBD |                TBD | Optional                  |
| Full test suite execution time |              TBD |                TBD | Recorded from test runner |

The main goal of refactoring is not necessarily to make the program faster. The primary goal is to improve design, maintainability, extensibility, and safety.

## 10. Suggested Commands for Collecting Metrics

### 10.1. Count Files

```bash
find . -type f \( -name "*.h" -o -name "*.hpp" -o -name "*.cpp" \) | wc -l
```

### 10.2. Count Lines of Code

```bash
find . -type f \( -name "*.h" -o -name "*.hpp" -o -name "*.cpp" \) -print0 | xargs -0 wc -l
```

### 10.3. Run Build

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
```

### 10.4. Run Tests

```bash
ctest --test-dir cmake-build-debug --output-on-failure
```

### 10.5. Check Git Difference Between Versions

```bash
git diff before-refactoring..main --stat
```

### 10.6. View Changed Files

```bash
git diff before-refactoring..main --name-status
```

## 11. Baseline Results

This section describes the initial state of the project before code refactoring.

| Metric | Baseline Result |
|---|---|
| CMake configure | Successful using CLion CMake profile |
| Build | Successful |
| Build environment | CLion bundled CMake |
| Tests | To be expanded and re-run during refactoring |
| Number of main source/header files | 5 |
| Main project files | `Graph.h`, `GraphAlgorithms.h`, `Network.h`, `NetworkSimulator.h`, `main.cpp` |
| Notes | The original project builds successfully in CLion. The baseline build result is recorded before changing the source code. |

## 12. Final Results

This section describes the state of the project after refactoring.

| Metric | Final Result |
|---|---|
| CMake configure | Successful using CLion CMake profile |
| Build | Successful |
| Build environment | CLion bundled CMake |
| Main executable target | `network_app` |
| Core library target | `network_core` |
| Test target | `tests_runner` |
| Tests | Successfully built and expanded |
| Number of main source/header areas | `app/`, `include/network/`, `tests/`, `docs/` |
| Public headers location | `include/network/` |
| UML source files | Stored in `docs/uml/source/` |
| UML generated images | Stored in `docs/uml/images/` |
| Doxygen configuration | Added as `Doxyfile` |
| Notes | The refactored project separates the application entry point, reusable core logic, public headers, tests, UML diagrams, and documentation. |

## 13. Final Conclusion

The refactoring improved the internal structure of the network routing simulator without intentionally changing its main behavior.

The most important improvements are:

- the application entry point was separated into the `app/` directory;
- public headers were moved into the `include/network/` directory;
- reusable core logic was extracted into the `network_core` CMake interface library;
- the main application and unit tests now use the same core library;
- raw owning pointers in `NetworkSimulator` were replaced with `std::unique_ptr<Device>`;
- manual memory cleanup was removed;
- simulator query methods were added to improve encapsulation and testability;
- additional unit tests were added for simulator device registry behavior and error handling;
- UML source diagrams and generated images were added;
- Doxygen configuration was added for generated code documentation.

The project became more modular, safer in terms of memory ownership, easier to test, and easier to explain using UML diagrams.

The main goal of the refactoring was not to significantly improve runtime performance, but to improve object-oriented design, maintainability, extensibility, and documentation quality.