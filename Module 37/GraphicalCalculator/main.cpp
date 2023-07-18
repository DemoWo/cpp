#include <QApplication>
#include "./ui_calculator.h"
#include "calculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CCalculator window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);
    window.textEdit = calculator.textEdit;
    window.textEdit_2 = calculator.textEdit_2;
    window.textBrowser = calculator.textBrowser;
    window.resize(480,640);
    window.show();
    return QApplication::exec();
}
