#include <iostream>
#include <QtGui/QtGui>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QSlider>
#include <QSpinBox>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QSoundEffect>

class ImageButton : public QPushButton
{
    Q_OBJECT
public:
    ImageButton() = default;
    explicit ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    [[nodiscard]] QSize sizeHint() const override;
    [[nodiscard]] QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
    void soundButton();

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
    QSoundEffect effect;
};
