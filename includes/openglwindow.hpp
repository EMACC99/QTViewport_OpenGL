#pragma once
#include <QMainWindow>
#include <QString>
#include <QSurfaceFormat>
#include <QTimer>
#include <QImage>

#include <filesystem>
#ifdef __APPLE__
    #include <OpenGL/glu.h>
#else
    #include <GL/glu.h>
#endif

#include <QOpenGLFunctions>
#include <QOpenGLWindow>
#include <QOpenGLWidget>
#include <QtOpenGL>

constexpr float rotate = 5.f;
namespace fs = std::filesystem;
class MainWindow : public QOpenGLWidget{
    
    Q_OBJECT
public:
    MainWindow(const int &example, QWidget *parent = 0);
    ~MainWindow();
    void loadTexture(const std::string &filename);
    int list;
    int example;
    bool auto_rotate = true;
    float initial_rotation = 0.f;
    std::array<float, 3> rotate_axis{1.f,1.f,0.f};
    QOpenGLTexture *m_texture;

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    QTimer timer;
    QOpenGLFunctions *gl;
};