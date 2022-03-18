QT+= core gui opengl widgets

SOURCES += \
    src/main.cpp\
    src/openglwindow.cpp\
    src/ejemplos.cpp

HEADERS+= includes/openglwindow.hpp includes/gl_debug.hpp includes/ejemplos.hpp

QMAKE_CXXFLAGS+= -std=c++17 -g -Wno-deprecated-declarations

CONFIG += debug
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -Os

macx {
	LIBS += -framework OpenGL

}
else{
	LIBS += -lGL -lglut -lGLU
}
TARGET = openglwindow

