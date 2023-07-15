#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QSlider>
#include <QSpinBox>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

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

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
};