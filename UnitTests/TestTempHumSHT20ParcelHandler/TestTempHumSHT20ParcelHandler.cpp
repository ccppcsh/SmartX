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
    void handleParcel_ValidParcel_SensorValuesRight_data();
    void handleParcel_ValidParcel_SensorValuesRight();
    void handleParcel_InvalidData_ErrorSignalEmited_data();
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

void TestTempHumSHT20ParcelHandler::handleParcel_ValidParcel_SensorValuesRight_data()
{
    // Setup table
    QTest::addColumn<QString>("parcelBytes");
    QTest::addColumn<float>("tempValueExpected");
    QTest::addColumn<float>("humidityValueExpected");

    // Add cases
    QTest::newRow("Parcel with positive temperature and humidity") << "Temp=26.170 Humi=51.240" << (float) 26.170 << (float) 51.240;
    QTest::newRow("Parcel without point after value") << "Temp=26 Humi=51" << (float) 26.0 << (float) 51.0;
    QTest::newRow("Parcel with negative temperature") << "Temp=-40.124 Humi=51" << (float) -40.124 << (float) 51.0;
}

void TestTempHumSHT20ParcelHandler::handleParcel_ValidParcel_SensorValuesRight()
{
    // Arrange
    QFETCH(QString, parcelBytes);
    QFETCH(float, tempValueExpected);
    QFETCH(float, humidityValueExpected);

    Parcel parcel;
    for (int i = 0; i < parcelBytes.length(); i++)
        parcel << parcelBytes.at(i).toLatin1();

    QSignalSpy spy(handler, SIGNAL(eventOccured(int)));

    // Act
    emit mockParserSignalParcelBuilt(parcel);

    // Assert
    QCOMPARE(spy.count(), 2);

    QList<QVariant> arguments = spy.takeFirst();

    QCOMPARE((int) TempHumSHT20ParcelHandler::TEMPERATURE_VALUE_UPDATED, arguments.at(0).toInt());
    QCOMPARE(tempValueExpected, handler->getTempValue());

    arguments = spy.takeFirst();
    QCOMPARE((int) TempHumSHT20ParcelHandler::HUMIDITY_VALUE_UPDATED, arguments.at(0).toInt());
    QCOMPARE(humidityValueExpected, handler->getHumidityValue());
}

void TestTempHumSHT20ParcelHandler::handleParcel_InvalidData_ErrorSignalEmited_data()
{
    QTest::addColumn<QString>("parcelBytes");

    //Add cases
    QTest::newRow("Error in temperature value") << "Temp=26e170 Humi=51.240";
    QTest::newRow("Any char instead of first equal char") << "Temp!26.170 Humi=51.240";
    QTest::newRow("Any char instead of second equal char") << "Temp=26.170 Humi!51.240";
}
void TestTempHumSHT20ParcelHandler::handleParcel_InvalidData_ErrorSignalEmited()
{
    // Arrange
    QFETCH(QString, parcelBytes);
    Parcel parcel;
    for (int i = 0; i < parcelBytes.length(); i++)
        parcel << parcelBytes.at(i).toLatin1();

    QSignalSpy spy(handler, SIGNAL(eventOccured(int)));

    // Act
    emit mockParserSignalParcelBuilt(parcel);

    // Assert
    QCOMPARE(spy.count(), 1);

    QList<QVariant> arguments = spy.takeFirst();

    QCOMPARE((int) TempHumSHT20ParcelHandler::PARCEL_NOT_RECOGNIZED, arguments.at(0).toInt());
}

QTEST_APPLESS_MAIN(TestTempHumSHT20ParcelHandler)

#include "TestTempHumSHT20ParcelHandler.moc"
