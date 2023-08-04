#include "widget.h"

Widget::Widget(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QObject::connect(ui.phone, &QLineEdit::textChanged, [this](QString text) {
        QRegularExpression re("^\\+[0-9]{11}$");
        if (re.match(text).hasMatch()) {
            ui.status->setText("OK");
            ui.status->setStyleSheet("QLabel { color: green; }");
        } else {
            ui.status->setText("Non OK");
            ui.status->setStyleSheet("QLabel { color: red; }");
        }
    });
}
