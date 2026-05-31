# Extra Task 1d — UML Tool Retrospective

## 1. Tool Used

For UML modeling in this laboratory work, I used PlantUML together with the PlantUML plugin for CLion.

PlantUML was used to create UML diagrams as text-based `.puml` source files. The CLion plugin was used to preview diagrams and export them as PNG images.

## 2. Why This Tool Was Chosen

PlantUML was chosen because it is convenient for storing diagrams in a Git repository.

The main reasons for choosing PlantUML were:

- diagrams are described as plain text;
- `.puml` files can be committed to Git;
- changes in diagrams can be reviewed through Git diff;
- generated images can be exported and stored in the repository;
- PlantUML supports many UML diagram types;
- the tool integrates with CLion through a plugin.

This was useful because the laboratory work required both diagram source files and generated images.

## 3. Installation and Setup

The setup process was mostly simple.

The PlantUML plugin was installed directly from CLion when the IDE suggested installing it for `.puml` files. After installation, CLion was able to preview PlantUML diagrams inside the editor.

The main setup steps were:

1. create `.puml` files in `docs/uml/source/`;
2. install the PlantUML plugin in CLion;
3. open a `.puml` file;
4. check the preview;
5. export the diagram as a PNG image;
6. save generated images to `docs/uml/images/`.

## 4. Documentation Quality

PlantUML documentation is useful, but it can be slightly overwhelming because it supports many diagram types and many syntax variations.

For common diagrams such as Class, Use Case, Sequence, Activity, State, Component, Package, Object, and Deployment diagrams, the syntax is understandable after several examples.

The documentation is especially helpful when looking for exact syntax for:

- inheritance;
- dependencies;
- notes;
- actors and use cases;
- sequence diagram participants;
- component diagrams;
- packages;
- state transitions.

## 5. Ease of Use

PlantUML is convenient after the basic syntax is understood.

The most useful aspect is that diagrams can be written and edited as code. This makes it easier to keep diagrams organized in the repository.

Compared with manual diagram editors, PlantUML requires less mouse-based editing. However, it also requires more attention to syntax.

## 6. Supported UML Diagram Types

PlantUML supports many UML diagram types that are useful for this laboratory work.

In this project, I used the following types:

- Use Case diagram;
- Class diagram;
- Component diagram;
- Package diagram;
- Sequence diagram;
- Activity diagram;
- State diagram;
- Object diagram;
- Deployment diagram.

These diagrams were enough to describe the system from different points of view: user interaction, structure, behavior, runtime examples, and deployment/build environment.

Some UML types were not used in the main refactoring part because they were less useful for the selected project or would duplicate already described behavior.

## 7. Additional Features Used

The most useful additional feature was exporting diagrams to PNG images.

This was important because the laboratory work required both editable diagram source files and generated images.

The repository contains:

```text
docs/uml/source/
```

for PlantUML source files and:

```text
docs/uml/images/
```

for generated PNG images.

## 8. Convenience During Work

PlantUML was convenient for iterative work.

When the project structure changed, it was easy to update the corresponding diagram by editing text. For example, after refactoring the project into `app/`, `include/network/`, and `network_core`, the Component and Package diagrams were updated by changing the `.puml` files.

The plugin preview in CLion made it possible to check diagrams without leaving the IDE.

## 9. Tool Behavior

The behavior of the PlantUML plugin was mostly predictable.

The main actions were clear:

- open `.puml` file;
- view preview;
- export image;
- save PNG file.

One minor inconvenience was that exported PNG files could receive long automatically generated names based on diagram titles. Because of this, the generated images had to be renamed manually to match the source file names.

## 10. Problems Encountered

The main problems were:

- understanding the correct PlantUML syntax for some diagram types;
- exporting PNG files with clean file names;
- making sure source files and generated images were both stored in the repository.

These problems were solved by checking the diagram preview in CLion and manually organizing the generated images in the `docs/uml/images/` directory.

## 11. Positive Aspects

Positive aspects of PlantUML:

- diagrams are text-based;
- diagrams are easy to store in Git;
- changes are easy to track;
- the syntax is compact;
- the tool supports many UML diagram types;
- the CLion plugin provides convenient preview;
- generated images can be exported for viewing on GitHub.

## 12. Negative Aspects

Negative aspects of PlantUML:

- syntax errors can be confusing at first;
- complex diagrams may become harder to read as text;
- layout is generated automatically and is not always perfect;
- exported image names may need manual cleanup;
- visual customization is less direct than in drag-and-drop tools.

## 13. What I Would Do the Same or Differently

I would use PlantUML again for a similar laboratory work because it works well with Git and allows diagrams to be stored together with code.

I would do the following the same way:

- keep `.puml` files in a separate `docs/uml/source/` directory;
- keep generated images in `docs/uml/images/`;
- use meaningful file names;
- create diagrams gradually as the architecture changes.

I would improve the process by creating a small script for generating all PNG images automatically instead of exporting diagrams one by one manually.

## 14. Conclusion

PlantUML with the CLion plugin was a suitable tool for this laboratory work.

It helped create UML diagrams in a reproducible and version-controlled way. The text-based format made the diagrams easy to store in Git, while generated PNG images made them easy to view without additional tools.

Overall, PlantUML was a good choice for UML modeling in this project.