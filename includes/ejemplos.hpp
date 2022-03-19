#pragma once

#include <QMessageBox>

#ifdef __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

namespace ejemplos {

    namespace {
        void ejemplo1_init();
        void ejemplo1();
        void ejemplo2_init();
        void ejemplo2(int *list);
        void ejemplo4_init();
        void ejemplo4();
    }

    void initialize_ejemplo(const int &ejemplo, int *list);

    void ejemplo(const int &ejemplo, int *list);

}