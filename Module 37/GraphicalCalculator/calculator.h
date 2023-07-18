//
// Created by Demon on 16.07.2023.
//

#ifndef GRAPHICALCALCULATOR_CALCULATOR_H
#define GRAPHICALCALCULATOR_CALCULATOR_H
#include <QMainWindow>
#include <QTextEdit>
#include <QTextBrowser>

class CCalculator : public QMainWindow
{
    Q_OBJECT

public:
    CCalculator(QWidget* parent = nullptr): QMainWindow(parent) {}

    QTextEdit* textEdit = nullptr;
    QTextEdit* textEdit_2 = nullptr;
    QTextBrowser* textBrowser = nullptr;
    void setTextEdite(  QString, QString, QString );

public slots:
    void clickDel(){ setTextEdite(QString(textEdit->toPlainText()), QString(textEdit_2->toPlainText()), "/"); };
    void clickPlus(){ setTextEdite(QString(textEdit->toPlainText()), QString(textEdit_2->toPlainText()), "+"); };
    void clickMinus(){ setTextEdite(QString(textEdit->toPlainText()), QString(textEdit_2->toPlainText()), "-"); };
    void clickMulti(){ setTextEdite(QString(textEdit->toPlainText()), QString(textEdit_2->toPlainText()), "*"); };

};
#endif //GRAPHICALCALCULATOR_CALCULATOR_H
