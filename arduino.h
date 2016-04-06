// Author: Manash 
// License: MIT

#ifndef ARDUINO_H
#define ARDUINO_H

#include <QDialog>
#include <QString>
#include <QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QKeyEvent>


namespace Ui {
class Arduino;
}

class Arduino : public QDialog
{
    Q_OBJECT

public:
    explicit Arduino(QWidget *parent = 0);
    ~Arduino();

public slots:
    void setPortName();
    void setBaudRate();
    void connectArduino();


    // Controls
    void forward();
    void backward();
    void left();
    void right();
    void stop();



private slots:
   // void on_speedPushButton_clicked();

    void on_forwardButton_clicked();

    void on_aboutButton_clicked();

    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void on_backwardButton_clicked();

    void on_stopButton_clicked();

    void on_highspeed_clicked();

    void on_mediumspeed_clicked();

    void on_lowspeed_clicked();

private:
    Ui::Arduino *ui;
    QSerialPort *arduino;
    QString currentPort;
    QList <QString> baudRateList;
    QList <QSerialPortInfo> ports;
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *e);
    QByteArray speed;
    int baudRate;

};

#endif // ARDUINO_H
