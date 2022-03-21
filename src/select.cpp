#include "includes/select.hpp"


ExampleSelect::ExampleSelect(QWidget *parent) : QWidget(parent){
    ui.setupUi(this);

    this -> setWindowFlag(Qt::Widget);
    
    ui.EjemplcomboBox->addItems(this -> options);
    ui.EjemplcomboBox->setCurrentIndex(0);

    connect(ui.pushButton, &QPushButton::clicked, this, &ExampleSelect::on_Button_clicked);
}

ExampleSelect::~ExampleSelect(){

}

void ExampleSelect::on_Button_clicked(){
    MainWindow *w;
    w = new MainWindow (this->ui.EjemplcomboBox->currentIndex() + 1);
    QString s = "OpenGL " + this->ui.EjemplcomboBox->currentText();
    w -> setWindowTitle(s);
    w -> setAttribute(Qt::WA_DeleteOnClose);
    w -> resize(640,480);
    w -> show();
    
}
