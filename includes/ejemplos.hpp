#pragma once

#ifdef __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

namespace ejemplos {

    namespace {
        void basic_init();
        void ejemplo1_init();
        void ejemplo2_init();
        void ejemplo4_init();
    }

    void initialize_ejemplo(const int &ejemplo, int *list = 0);

    void ejemplo1();

    void ejemplo2(int *list);

    void ejemplo4();
}