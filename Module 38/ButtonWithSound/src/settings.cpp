#include "settings.h"

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap(":/img/btn.png");
    mButtonDownPixmap = QPixmap(":/img/btn_clicked.png");
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
    soundButton();
    update();
    QTimer::singleShot(150, this, &ImageButton::setUp);
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    effect.stop();
    update();
}

void ImageButton::soundButton()
{
    effect.setSource(QUrl::fromLocalFile(":/media/clicked.wav"));
    effect.setLoopCount(QSoundEffect::Infinite);
    effect.setVolume(0.5f);
    effect.play();
}
