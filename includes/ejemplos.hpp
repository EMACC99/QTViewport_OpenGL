#pragma once

#include "includes/openglwindow.hpp"

#include <array>
#include <functional>
#ifdef __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

constexpr float rotation_factor =  25.0;
namespace ejemplos {

    void initialize_ejemplo(MainWindow &mainwindow);

    void ejemplo(MainWindow &mainwindow);

}