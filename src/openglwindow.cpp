#include "includes/gl_debug.hpp"
#include "includes/openglwindow.hpp"
#include "includes/ejemplos.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>

using namespace std::chrono_literals;

MainWindow::MainWindow(const int &example, QWidget *parent) : QOpenGLWidget(parent){

    this -> example = example;
    this -> setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);
    
    // this->setSurfaceType(QWindow::OpenGLSurface);
    // this -> 
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2, 1);
    this->setFormat(format);

    this->create();
    qDebug() << context();
    // this->initializeGL(); // this causes a segfault bc calling a virtual method during construction bypasses a virtual dispacth and this is dangerous

    connect(&this->timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start(100ms);
}

MainWindow::~MainWindow() {
}

void MainWindow::initializeGL(){ 
        resizeGL(this->width(), this->height());
        ejemplos::initialize_ejemplo(this -> example, &(this -> list));
    }

void MainWindow::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    float aspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 100.0);
}

void MainWindow::paintGL(){
    ejemplos::ejemplo(this -> example, &(this -> list), this -> rotate, &(this -> initial_roation));
}


void MainWindow::mouseMoveEvent(QMouseEvent *event){
    // qDebug() << event->buttons(); 
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()){
    case Qt::Key_D:
        // rotate or smth
        break;
    }
}
