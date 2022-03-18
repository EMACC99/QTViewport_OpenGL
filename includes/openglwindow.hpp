#pragma once
#include <QMainWindow>
#include <QString>
#include <QSurfaceFormat>
#include <QTimer>
#include <GL/glu.h>
#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QtOpenGL>

class MainWindow : public QOpenGLWindow{
    
    Q_OBJECT
public:
    MainWindow(QWindow *parent = 0);
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
};