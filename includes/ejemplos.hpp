#pragma once

#ifdef __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

namespace ejemplos {

    void initialize_ejemplo(const int &ejemplo, int *list);

    void ejemplo(const int &ejemplo, int *list);

}