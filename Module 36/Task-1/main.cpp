#include "src/settings.h"

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Stop");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("D:\\Home Work\\cpp\\Module 36\\Task-1\\image\\up.png");
    mButtonDownPixmap = QPixmap("D:\\Home Work\\cpp\\Module 36\\Task-1\\image\\down.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}

void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void ImageButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(300, this, &ImageButton::setUp);
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}

//void sliderAndSpinbox()
//{
//    auto *slider = new QSlider(Qt::Horizontal);
//    auto *spinbox = new QSpinBox();
//    slider->setMinimum(0);
//    slider->setMaximum(100);
//    spinbox->setMinimum(0);
//    spinbox->setMaximum(100);
//    //
//    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
//    QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);
//
//    slider->resize(100, 10);
//    spinbox->resize(20, 50);
//    spinbox->move(900, 500);
//    slider->move(800, 200);
//
//    slider->show();
//    spinbox->show();
//}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    ImageButton redButton(nullptr);
    redButton.setFixedSize(200, 200);
    redButton.move(1000, 400);
    QObject::connect(&redButton,&QPushButton::clicked, [](){
        std::cout << "clicked\n";
    });
    redButton.show();

    return app.exec();
}

