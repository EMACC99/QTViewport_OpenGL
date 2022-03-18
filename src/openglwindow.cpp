#include "includes/gl_debug.hpp"
#include "includes/openglwindow.hpp"
#include "includes/ejemplos.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>

using namespace std::chrono_literals;

MainWindow::MainWindow(QWindow *parent) : QOpenGLWindow(new QOpenGLContext, QOpenGLWindow::NoPartialUpdate, parent)
{
    this->setSurfaceType(QWindow::OpenGLSurface);

    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2, 1);
    this->setFormat(format);

    this->create();
    qDebug() << context();
    this->initializeGL();

    connect(&this->timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(100ms);
}

MainWindow::~MainWindow() = default; 

void MainWindow::initializeGL(){ 
        resizeGL(this->width(), this->height());
        // ejemplos::initialize_ejemplo(2, &(this -> list));
        ejemplos::initialize_ejemplo(4);
    }

void MainWindow::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    float aspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 100.0);
}

void MainWindow::paintGL(){

    // ejemplos::ejemplo2(&(this -> list));
    ejemplos::ejemplo4();
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    // dosmth
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_D:
        // dosmth
        break;
    }
}