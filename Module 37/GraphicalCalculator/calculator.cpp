#include "calculator.h"

void CCalculator::setTextEdite(  QString text1, QString text2, QString symbol) {
    QString text3;
    bool okText1 = false;
    bool okText2 = false;
    double checkText1 = text1.toDouble(&okText1);
    double checkText2 = text2.toDouble(&okText2);
    if (okText1 && okText2) {
        if (symbol == "+") {
            text3 = QString::number(checkText1 + checkText2);
        }
        if (symbol == "-") {
            text3 = QString::number(checkText1 - checkText2);
        }
        if (symbol == "/") {
            if( checkText2 != 0 ) {
                text3 = QString::number(checkText1 / checkText2);
            } else {
                text3 = "Error!";
            }
        }
        if (symbol == "*") {
            text3 = QString::number(checkText1 * checkText2);
        }
    } else {
        text3 = "Error!";
    }
    textBrowser->setPlaceholderText(text3);
}
