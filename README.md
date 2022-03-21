# QTViewport for OpenGL

A simple QT viewport for OpenGL

## Requirements

* g++ or clang++
* Qt >= 5.15 [^1]
* qmake
* OpenGL

## Instructions

### Compilation

To compile just run

```sh
qmake
```

then

```sh
make
```

This will generate an executable named `openglwindow` on Linux or `openglwindow.app` on Mac.

### Run

* #### Linux

    ```sh
    ./openglwindow
    ```

* #### Mac

    ```sh
    open openglwindow.app
    ```
[^1]: Using QT6 is posible you just need to do the following:
    `<QtWidgets/QAction>` for `<QtGui/QAction>` in the file UI/select_example.hpp
