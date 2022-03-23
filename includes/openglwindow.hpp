#pragma once
#include <QMainWindow>
#include <QString>
#include <QSurfaceFormat>
#include <QTimer>

#ifdef __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QOpenGLWidget>
#include <QtOpenGL>

class MainWindow : public QOpenGLWidget{
    
    Q_OBJECT
public:
    MainWindow(const int &example, QWidget *parent = 0);
    ~MainWindow();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    QTimer timer;
    QOpenGLFunctions *gl;
    int list;
    int example;
    bool rotate = true;
    float initial_roation = 0.f;
};