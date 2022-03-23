#include "UI/select_example.hpp"
#include "includes/openglwindow.hpp"

class ExampleSelect : public QWidget{
    Q_OBJECT

public:
    ExampleSelect(QWidget *parent = nullptr);
    ~ExampleSelect();

protected:
    void on_Button_clicked();

private:
    Ui::Form ui;
    QStringList options = {"ejemplo 1", "ejemplo 2", "ejemplo 3", "ejemplo 4", "ejemplo 5"};

};