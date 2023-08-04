#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_widget.h"
#include <QRegularExpression>

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = Q_NULLPTR);

private:
    Ui::widgetClass ui;
};
