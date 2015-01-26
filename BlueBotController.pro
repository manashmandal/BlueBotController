#-------------------------------------------------
#
# Project created by QtCreator 2015-01-25T12:55:24
#
#-------------------------------------------------

QT       += core gui
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BlueBotController
TEMPLATE = app


SOURCES += main.cpp\
        arduino.cpp

HEADERS  += arduino.h

FORMS    += arduino.ui

RESOURCES += \
    arduinoResource.qrc


