# UML Diagrams

This directory contains UML diagrams for Laboratory Work 1a.

The diagrams describe the original version of the network routing simulator, the implemented refactoring, and the final refactored architecture.

## Directory Structure

```text
docs/uml/
├── README.md
├── source/
└── images/
```

## Source Files

The `source/` directory contains PlantUML source files.

Each `.puml` file describes one UML diagram and can be edited later.

## Generated Images

The `images/` directory contains generated PNG diagram images.

These images are created from PlantUML source files and can be viewed directly on GitHub.

## Diagrams

| Diagram | Source File | Image File | Purpose |
|---|---|---|---|
| Use Case | `source/use-case.puml` | `images/use-case.png` | Shows main user interactions with the simulator |
| Class Before Refactoring | `source/class-before.puml` | `images/class-before.png` | Shows the original class structure and raw pointer ownership |
| Class After Refactoring | `source/class-after.puml` | `images/class-after.png` | Shows the refactored class structure and smart pointer ownership |
| Component | `source/component-after.puml` | `images/component-after.png` | Shows main software components after refactoring |
| Package | `source/package-after.puml` | `images/package-after.png` | Shows logical package structure |
| Sequence | `source/sequence-send-packet.puml` | `images/sequence-send-packet.png` | Shows packet routing interaction |
| Activity | `source/activity-routing.puml` | `images/activity-routing.png` | Shows routing workflow |
| State | `source/state-packet.puml` | `images/state-packet.png` | Shows packet lifecycle |
| Object | `source/object-demo-network.puml` | `images/object-demo-network.png` | Shows example runtime network objects |
| Deployment | `source/deployment.puml` | `images/deployment.png` | Shows development, build, and documentation environment |
| Communication | `source/communication-routing.puml` | `images/communication-routing.png` | Shows object collaboration during packet routing |
| Composite Structure | `source/composite-structure-network.puml` | `images/composite-structure-network.png` | Shows internal parts of `NetworkSimulator` |
| Timing | `source/timing-packet-routing.puml` | `images/timing-packet-routing.png` | Shows packet state and route progress over time |
| Interaction Overview | `source/interaction-overview-routing.puml` | `images/interaction-overview-routing.png` | Combines routing workflow with referenced interactions |

## Notes

Both source files and generated images are stored in the repository.

This is important because the source files allow diagrams to be edited, while generated images allow diagrams to be viewed without installing additional tools.

The `class-before` and `class-after` diagrams are especially important because they show the difference between the original design and the refactored design.