#include "mainwindow.h"

MainWindow::MainWindow( QObject *parent ) : QObject( parent )
{

}

MainWindow::~MainWindow()
{

}

void MainWindow::setButtonClicckedNumChannel( const QString text )
{
    numChanel = text;
    emit text_field_statusChanged();
}

void MainWindow::setButtonClicckedChannel( const QString text )
{
    int num;
    if( text == "+" ) {
        num = numChanel.toInt()  + 1;
    }
    if( text == "-" ) {
        num = numChanel.toInt()  - 1;
    }
    if( num >= 0 ) {
        numChanel = QString::number(num);
        emit text_field_statusChanged();
    }
}

void MainWindow::setButtonClicckedVolume( const QString text)
{
    int vol;
    if( text == "+" ) {
        vol = volume.toInt()  + 10;
    }
    if( text == "-" ) {
        vol = volume.toInt()  - 10;
    }
    if( vol <= 100 && vol >= 0) {
        volume = QString::number(vol);
        emit text_field_statusChanged();
    }
}

QString MainWindow::text_field_status() const
{
    QString result = "Channel: " + numChanel + ", Volume: " + volume;
    return result;
}
