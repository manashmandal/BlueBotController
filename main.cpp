#include "arduino.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Arduino w;
    w.setWindowTitle("Arduino-Bluetooth Bot Controller [1.0 (Alpha)]");
    //QIcon windowIcon(":/icons/windowicon.png");
   // w.setWindowIcon(QIcon("windowicon.png"));
    w.show();

    return a.exec();
}
