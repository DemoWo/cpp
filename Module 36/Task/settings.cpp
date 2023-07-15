#include "settings.h"

ImageCircle::ImageCircle(QWidget* parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    red = QPixmap("D:\\Home Work\\cpp\\Module 36\\Task\\image\\red.png");
    green = QPixmap("D:\\Home Work\\cpp\\Module 36\\Task\\image\\green.png");
    yellow = QPixmap("D:\\Home Work\\cpp\\Module 36\\Task\\image\\yellow.png");
    current = green;
    setGeometry(current.rect());
}
void ImageCircle::paintEvent(QPaintEvent* e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), current);
}
QSize ImageCircle::minimumSizeHint() const {
    return QSize(100, 100);
}
void ImageCircle::setRed() {
    current = red;
    update();
}
void ImageCircle::setGreen() {
    current = green;
    update();
}
void ImageCircle::setYellow() {
    current = yellow;
    update();
}
