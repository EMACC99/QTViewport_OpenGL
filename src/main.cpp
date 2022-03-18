/****************************************************************************
https://www.youtube.com/watch?v=a2CpOQsgB84
https://www.youtube.com/watch?v=6eu8oMULqaU
Tutoriales de Parwiz Forogh
****************************************************************************/

#include "openglwindow.hpp"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc,argv);
    MainWindow w;
    w.setTitle("OpenGL");
    w.resize(640,480);
    w.show();

    return a.exec();
}
