#include "includes/select.hpp"
#include <QApplication>

int main(int argc, char **argv){

    QApplication app(argc, argv);

    ExampleSelect ui;
    ui.show();

    return app.exec();
}