#include "imageblurer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageBlurer w;
    w.show();
    return a.exec();
}
