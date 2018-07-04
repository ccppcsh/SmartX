#-------------------------------------------------
#
# Project created by QtCreator 2018-05-26T19:02:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += serialport

TARGET = SmartX
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += RUN_SYSTEM
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Device/BaseDevice.cpp \
    Sensors/SensorData.cpp \
    Sensors/BaseSensor.cpp \
    Communication/BaseCommunicationInterface.cpp \
    Communication/SerialInterface.cpp \
    ProtocolParser/BaseParser.cpp \
    ProtocolParser/Parcel.cpp \
    ProtocolParser/BaseParcelHandler.cpp \
    Sensors/DSDTechSHT20/TempHumSHT20Sensor.cpp \
    Sensors/DSDTechSHT20/TempHumSHT20Parser.cpp \
    Sensors/DSDTechSHT20/TempHumSHT20ParcelHandler.cpp \
    View/BaseSensorView.cpp

HEADERS += \
        mainwindow.h \
    Sensors/BaseSensor.h \
    Device/BaseDevice.h \
    Sensors/SensorData.h \
    Communication/BaseCommunicationInterface.h \
    Communication/SerialInterface.h \
    run_config.h \
    ProtocolParser/BaseParser.h \
    ProtocolParser/Parcel.h \
    ProtocolParser/BaseParcelHandler.h \
    Sensors/DSDTechSHT20/TempHumSHT20Sensor.h \
    Sensors/DSDTechSHT20/TempHumSHT20Parser.h \
    Sensors/DSDTechSHT20/TempHumSHT20ParcelHandler.h \
    View/BaseSensorView.h

FORMS += \
        mainwindow.ui
