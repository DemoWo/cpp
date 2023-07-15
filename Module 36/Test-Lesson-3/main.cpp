#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    QPushButton *button1 = new QPushButton( "One", window);
    QPushButton *button2 = new QPushButton( "Two", window);
    QPushButton *button3 = new QPushButton( "Three", window);
//    button1->move(40,50);
//    button2->move(140,150);
//    button3->move(200,200);

//    auto *layout = new QVBoxLayout(window);
//    layout->addWidget(button1);
//    layout->addWidget(button2);
//    layout->addWidget(button3);

    auto *layout = new QGridLayout(window);
    layout->addWidget(button1,0,0);
    layout->addWidget(button2,0,1);
    layout->addWidget(button3,1,0,1,2);

    window->resize(300,300);
    window->move(1000,500);
    window->show();
    return app.exec();
}
