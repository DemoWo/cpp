
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include <QSharedDataPointer>
#include <QObject>
#include <iostream>

class MainWindow : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text_field_status READ text_field_status NOTIFY text_field_statusChanged)

public:

    explicit MainWindow ( QObject *parent = nullptr );
    ~MainWindow();

    QString text_field_status() const;
    Q_INVOKABLE void setButtonClicckedNumChannel( const QString );
    Q_INVOKABLE void setButtonClicckedChannel( const QString );
    Q_INVOKABLE void setButtonClicckedVolume( const QString );


private:
    QString numChanel = "0";
    QString volume = "0";
    QString status;

signals:
    void text_field_statusChanged();

};

#endif // MAINWINDOW_H
