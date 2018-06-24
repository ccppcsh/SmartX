VPATH += $$PWD 
INCLUDEPATH += $$PWD

SOURCES += \
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
