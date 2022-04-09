#include "includes/gl_debug.hpp"
#include "includes/ejemplos.hpp"
#include "includes/openglwindow.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <string>

using namespace std::chrono_literals;

MainWindow::MainWindow(const int &example, QWidget *parent) : QOpenGLWidget(parent), m_texture(0){

    this -> example = example;
    this -> setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);
    
    // this->setSurfaceType(QWindow::OpenGLSurface);
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
    makeCurrent();

    delete m_texture;

    doneCurrent();
}

void MainWindow::initializeGL(){ 
        resizeGL(this->width(), this->height());
        ejemplos::initialize_ejemplo(*this);
    }

void MainWindow::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
    float aspect = (GLfloat)w / (GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 100.0);
}

void MainWindow::paintGL(){
    ejemplos::ejemplo(*this);
}


void MainWindow::mouseMoveEvent(QMouseEvent *event){
    // qDebug() << event->buttons(); 
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()){
    case Qt::Key_D:
        // rotate or smth
        this -> auto_rotate = false;
        this -> initial_rotation += rotate;

        this -> rotate_axis[0] = 0.f;
        this -> rotate_axis[1] = 1.f;
        this -> rotate_axis[2] = 0.f;
        
        break;

    case Qt::Key_A:
        this -> auto_rotate = false;
        this -> initial_rotation -= rotate;
        
        this -> rotate_axis[0] = 0.f;
        this -> rotate_axis[1] = 1.f;
        this -> rotate_axis[2] = 0.f;

        break;
    
    case Qt::Key_W:
        this -> auto_rotate = false;
        this -> initial_rotation += rotate;

        this -> rotate_axis[0] = 1.f;
        this -> rotate_axis[1] = 0.f;
        this -> rotate_axis[2] = 0.f; 

        break;

    case Qt::Key_S:
        this -> auto_rotate = false;
        this -> initial_rotation -= rotate;

        this -> rotate_axis[0] = 1.f;
        this -> rotate_axis[1] = 0.f;
        this -> rotate_axis[2] = 0.f; 

        break;

    case Qt::Key_R:
        this -> auto_rotate = true;
        for (unsigned long i = 0; i < this -> rotate_axis.size(); ++i)
            this -> rotate_axis[i] = 1.f;
        
        break;
    }

}


void MainWindow::loadTexture(const std::string &filename){
    fs::path path = "assets/" + filename;
    path = fs::absolute(path);

    std::unique_ptr<QOpenGLTexture> m_texture( new QOpenGLTexture(QImage(path.c_str())));
    if (!m_texture -> isCreated()){
        std::cerr << "Failed to load texture" << std::endl;
        exit(EXIT_FAILURE);
    }
    // m_texture -> setWrapMode(QOpenGLTexture::DirectionS, QOpenGLTexture::Repeat);
    // m_texture -> setWrapMode(QOpenGLTexture::DirectionT, QOpenGLTexture::Repeat);

    // m_texture -> setMinificationFilter(QOpenGLTexture::Linear);
    // m_texture -> setMagnificationFilter(QOpenGLTexture::Linear);


    
}