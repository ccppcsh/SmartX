#include <QString>
#include <QtTest>
#include "Sensors/DSDTechSHT20/TempHumSHT20ParcelHandler.h"

class TestTempHumSHT20ParcelHandler : public QObject
{
    Q_OBJECT

public:
    TestTempHumSHT20ParcelHandler();

private Q_SLOTS:
    void init();
    void cleanup();
    void handleParcel_ValidParcel_SignalsEmited();
    void handleParcel_ValidParcel_SensorValuesRight();
    void handleParcel_InvalidData_ErrorSignalEmited();
signals:
    void mockParserSignalParcelBuilt(const Parcel& parcel);
private:
    TempHumSHT20ParcelHandler* handler;
};

TestTempHumSHT20ParcelHandler::TestTempHumSHT20ParcelHandler()
{
}

void TestTempHumSHT20ParcelHandler::init()
{
    handler = new TempHumSHT20ParcelHandler();
    QObject::connect(this, SIGNAL(mockParserSignalParcelBuilt(Parcel)), handler, SLOT(onParcelBuilt(const Parcel&)));
}

void TestTempHumSHT20ParcelHandler::cleanup()
{
    QObject::disconnect(this, SIGNAL(mockParserSignalParcelBuilt(Parcel)), handler, SLOT(onParcelBuilt(const Parcel&)));
    delete handler;
}

void TestTempHumSHT20ParcelHandler::handleParcel_ValidParcel_SignalsEmited()
{
    // Arrange
    Parcel parcel;
    QString testStr = QString("Temp=26.170 Humi=51.240");

    for (int i = 0; i < testStr.length(); i++)
        parcel << testStr.at(i).toLatin1();

    QSignalSpy spy(handler, SIGNAL(eventOccured(int)));
    // Act
    emit mockParserSignalParcelBuilt(parcel);

    // Assert
    QCOMPARE(spy.count(), 2);

}

void TestTempHumSHT20ParcelHandler::handleParcel_ValidParcel_SensorValuesRight()
{
    // Handle parcel like "TEMP=29.4 HUM=75"
    // Temp = 29
    // Temp = 29,0
    // Temp = -40
}
void TestTempHumSHT20ParcelHandler::handleParcel_InvalidData_ErrorSignalEmited()
{
    // Temp = 25.c Hum=dfdsf
}

QTEST_APPLESS_MAIN(TestTempHumSHT20ParcelHandler)

#include "TestTempHumSHT20ParcelHandler.moc"
