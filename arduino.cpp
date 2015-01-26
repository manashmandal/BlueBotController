#include "arduino.h"
#include "ui_arduino.h"
#include <QIcon>
#include <QtCore>



Arduino::Arduino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arduino)
{


    ui->setupUi(this);
    setWindowIcon(QIcon(":/icon"));
    arduino = new QSerialPort(this);



    baudRateList << "1200" << "2400" << "4800" << "9600" << "19200" << "38400" << "57600" << "115200";

    ports = QSerialPortInfo::availablePorts();
    QListIterator <QSerialPortInfo> iter(ports);
    QListIterator <QString> baudIter(baudRateList);

    while (iter.hasNext()){
        ui->comportBox->addItem(iter.next().portName());
    }

    while (baudIter.hasNext()){
        ui->baudrateBox->addItem(baudIter.next());
    }

    ui->baudrateBox->setCurrentText("9600");

    connect(ui->comportBox, SIGNAL(currentTextChanged(QString)), this, SLOT(setPortName()));
    connect(ui->baudrateBox, SIGNAL(currentTextChanged(QString)),this, SLOT(setBaudRate()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectArduino()));



    connect(ui->forwardButton, SIGNAL(pressed()), this, SLOT(forward()));
    connect(ui->backwardButton, SIGNAL(pressed()), this, SLOT(backward()));
    connect(ui->leftButton, SIGNAL(pressed()), this, SLOT(left()));
    connect(ui->rightButton, SIGNAL(pressed()), this, SLOT(right()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stop()));


    connect(ui->forwardButton, SIGNAL(released()), this, SLOT(stop()));
   connect(ui->leftButton, SIGNAL(released()), this, SLOT(stop()));
    connect(ui->rightButton, SIGNAL(released()), this, SLOT(stop()));
    connect(ui->backwardButton, SIGNAL(released()), this, SLOT(stop()));





    ui->statusLabel->setText("Connect BT Module");


    arduino->setPortName(currentPort);


    ui->speedLabel->setText("Running at default speed: 230");
}


void Arduino::forward()
{
        arduino->write("W");
}

void Arduino::backward()
{

        arduino->write("S");
}

void Arduino::left()
{

        arduino->write("A");
}

void Arduino::right()
{

        arduino->write("D");
}

void Arduino::stop()
{
        arduino->write("q");
}




void Arduino::keyPressEvent(QKeyEvent *event)

{

     //ui->statusLabel->setText( QString("You have pressed %1").arg(event->key()));
    switch( event->key()){

    case Qt::Key_W:

        arduino->write("W");
        break;
    case Qt::Key_S:

        arduino->write("S");
        break;
    case Qt::Key_A:
        arduino->write("A");
        break;
    case Qt::Key_D:
        arduino->write("D");
        break;
    case Qt::Key_H:
        arduino->write("H");
        break;
    case Qt::Key_L:
        arduino->write("L");
        break;

    default:
        arduino->write("q");
        break;
    }

}

void Arduino::keyReleaseEvent(QKeyEvent *event)
{
    if (!(event->isAutoRepeat()))
    arduino->write("q");
}

void Arduino::setPortName()
{
    currentPort = ui->comportBox->currentText();
    arduino->setPortName(currentPort);
}

void Arduino::setBaudRate()
{
    baudRate = (ui->baudrateBox->currentText()).toInt();
    //Debugging Purpose
    //QMessageBox::information(this, "Hello", ui->baudrateBox->currentText());
}




void Arduino::connectArduino()
{
    arduino->close();
    if (arduino->open(QIODevice::ReadWrite)){

        arduino->setBaudRate(baudRate);
        // 8bit mode
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        // Skipping hw/sw control
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        QMessageBox::information(this, "Connection Successful", "Successfully connected to " + currentPort);
        ui->statusLabel->setText("Connection Established! Press W/A/S/D to control");
    }
    else {
        QMessageBox::warning(this, "Failed", "Connection Failed");
    }
}

Arduino::~Arduino()
{
    arduino->close();
    delete ui;
}


void Arduino::on_forwardButton_clicked()
{
    if (!(arduino->isOpen())) QMessageBox::warning(this, "Connect the device", "Connect the device first!");

}

void Arduino::on_aboutButton_clicked()
{
    QMessageBox::information(this, "About Me", "I am Manash\nStudying EEE @KUET, Bangladesh\nThis app was written in Qt C++\nHope you like it :)");
}

void Arduino::on_leftButton_clicked()
{
    if (!(arduino->isOpen())) QMessageBox::warning(this, "Connect the device", "Connect the device first!");
}

void Arduino::on_rightButton_clicked()
{
    if (!(arduino->isOpen())) QMessageBox::warning(this, "Connect the device", "Connect the device first!");
}

void Arduino::on_backwardButton_clicked()
{
    if (!(arduino->isOpen())) QMessageBox::warning(this, "Connect the device", "Connect the device first!");
}

void Arduino::on_stopButton_clicked()
{
    if (!(arduino->isOpen())) QMessageBox::warning(this, "Connect the device", "Connect the device first!");
}

void Arduino::on_highspeed_clicked()
{
    if (!(arduino->isOpen())){
        QMessageBox::warning(this, "Connect the device", "Connect the device first!");
    } else {
        arduino->write("H");
        ui->speedLabel->setText("Running at High speed: 255");

    }
}

void Arduino::on_mediumspeed_clicked()
{
    if (!(arduino->isOpen())){
        QMessageBox::warning(this, "Connect the device", "Connect the device first!");
    } else {
        arduino->write("M");
        ui->speedLabel->setText("Running at Medium speed: 220");
    }
}

void Arduino::on_lowspeed_clicked()
{
    if (!(arduino->isOpen())){
        QMessageBox::warning(this, "Connect the device", "Connect the device first!");
    } else {
        arduino->write("L");
        ui->speedLabel->setText("Running at Low speed: 190");
    }
}
