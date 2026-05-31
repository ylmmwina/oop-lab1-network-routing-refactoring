# UML Diagrams

This directory contains UML diagrams for Laboratory Work 1.

The diagrams are used to describe the original version of the network routing simulator, the planned refactoring, and the final refactored architecture.

## Directory Structure

```text
docs/uml/
├── README.md
├── source/
└── images/
```

## Source Files

The `source/` directory contains PlantUML source files.

Each `.puml` file describes one UML diagram.

## Generated Images

The `images/` directory contains generated diagram images.

These images are created from PlantUML source files and can be viewed directly on GitHub.

## Planned Diagrams

| Diagram | Source File | Purpose |
|---|---|---|
| Use Case | `source/use-case.puml` | Shows main user interactions with the simulator |
| Class Before Refactoring | `source/class-before.puml` | Shows the original class structure |
| Class After Refactoring | `source/class-after.puml` | Shows the refactored class structure |
| Component | `source/component-after.puml` | Shows main software components |
| Package | `source/package-after.puml` | Shows logical package structure |
| Sequence | `source/sequence-send-packet.puml` | Shows packet routing interaction |
| Activity | `source/activity-routing.puml` | Shows routing workflow |
| State | `source/state-packet.puml` | Shows packet lifecycle |
| Object | `source/object-demo-network.puml` | Shows example runtime network objects |
| Deployment | `source/deployment.puml` | Shows deployment/build environment |

## Notes

Both source files and generated images should be stored in the repository.

This is important because the source files allow diagrams to be edited, while generated images allow diagrams to be viewed without installing additional tools.