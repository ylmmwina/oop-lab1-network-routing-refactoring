# Extra Task 1b — GitHub UML Modeling

## Selected Service

The selected service for conceptual and domain modeling is GitHub.

GitHub is modeled as a code repository hosting service that allows users to create repositories, manage branches, commit and push changes, open pull requests, review code, track issues, and run CI checks.

## Purpose

The purpose of this extra task is to describe the selected service using UML diagrams and a domain glossary.

This task focuses on conceptual and domain modeling. It does not require implementing code.

## Diagrams

| Diagram | Source File | Image File | Purpose |
|---|---|---|---|
| Use Case | `source/use-case-github.puml` | `images/use-case-github.png` | Shows main user interactions |
| Class | `source/class-github.puml` | `images/class-github.png` | Shows domain entities and relationships |
| Sequence | `source/sequence-pull-request.puml` | `images/sequence-pull-request.png` | Shows pull request workflow |
| Activity | `source/activity-issue-workflow.puml` | `images/activity-issue-workflow.png` | Shows issue workflow |
| State | `source/state-pull-request.puml` | `images/state-pull-request.png` | Shows pull request lifecycle |
| Component | `source/component-github.puml` | `images/component-github.png` | Shows main service components |

## Notes

The model does not describe the full internal implementation of GitHub.  
It describes the main concepts and workflows from the point of view of users and high-level architecture.
