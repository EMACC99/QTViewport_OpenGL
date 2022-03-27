#pragma once

#include <array>

#ifdef __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

constexpr float rotation_factor =  25.0;
namespace ejemplos {

    void initialize_ejemplo(const int &ejemplo, int *list);

    void ejemplo(const int &ejemplo, int *list, const bool &rotate, float *initial_rotation, const std::array<float, 3> &rotate_axis);

}