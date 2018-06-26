#include <QString>
#include <QtTest>
#include "Sensors/DSDTechSHT20/TempHumSHT20Parser.h"
#include "ProtocolParser/Parcel.h"

class TestTempHumSHT20ParserTest : public QObject
{
    Q_OBJECT

public:
    TestTempHumSHT20ParserTest();
private slots:
    void init();
    void cleanup();
    void parseBytes_ValidParcel_onParcelBuiltEmited();
    void parseBytes_ValidParcel_onParcelBuiltEmited_data();
    void parseBytes_ValidParcel_ParsedCorrect();
    void parseBytes_ControlByteLost_ParserSkipsThisParcel();
signals:
    void mockInterfaceSignalDataRecevied(const QByteArray& bytes);
private:
     TempHumSHT20Parser* parser;
};

TestTempHumSHT20ParserTest::TestTempHumSHT20ParserTest()
{

}


void TestTempHumSHT20ParserTest::init()
{
    // Create object and connect signals and slots
    parser = new TempHumSHT20Parser();
    QObject::connect(this, SIGNAL(mockInterfaceSignalDataRecevied(QByteArray)), parser, SLOT(onDataReceived(QByteArray)));
}

void TestTempHumSHT20ParserTest::cleanup()
{
    QObject::disconnect(this, SIGNAL(mockInterfaceSignalDataRecevied(QByteArray)), parser, SLOT(onDataReceived(QByteArray)));
    delete parser;
}
void TestTempHumSHT20ParserTest::parseBytes_ValidParcel_onParcelBuiltEmited_data()
{
    // Setup table
    QTest::addColumn<QString>("bytesStr");
    QTest::addColumn<int>("cntParcelExpected");

    // Add cases
    QTest::newRow("One parcel inside") << "\r\nPAYLOAD DATA\r\n" << 1;
    QTest::newRow("One parcel inside with trash before") << "TRASH\r\nPAYLOAD DATA\r\n" << 1;
    QTest::newRow("Three parcels inside") << "\r\nPAYLOAD DATA #1\r\nPAYLOAD DATA #2\r\nPAYLOAD DATA #3\r\n" << 3;
    QTest::newRow("Three parcels inside with trash before and after") << "TRASH BEFORE\r\nPAYLOAD DATA #1\r\nPAYLOAD DATA #2\r\nPAYLOAD DATA #3\r\nTRASH AFTER" << 3;
}

void TestTempHumSHT20ParserTest::parseBytes_ValidParcel_onParcelBuiltEmited()
{
    // Arrange
    QFETCH(QString, bytesStr);
    QFETCH(int, cntParcelExpected);

    QByteArray bytes = bytesStr.toLatin1();
    QSignalSpy spy(parser, SIGNAL(onParcelBuilt(const Parcel&)));

    // Act
    emit mockInterfaceSignalDataRecevied(bytes);

    // Assert
    QCOMPARE(spy.count(), cntParcelExpected);
}

void TestTempHumSHT20ParserTest::parseBytes_ValidParcel_ParsedCorrect()
{
    // Arrange
    TempHumSHT20Parser* bytesParser = new TempHumSHT20Parser();
    QVector<Parcel> parcels;

    QString bytesStr = "\r\nPAYLOAD BYTES\r\n";
    QString payloadBtes = "PAYLOAD BYTES";
    QObject::connect(this, SIGNAL(mockInterfaceSignalDataRecevied(QByteArray)), bytesParser, SLOT(onDataReceived(QByteArray)));
    QObject::connect(bytesParser, &TempHumSHT20Parser::onParcelBuilt, this, [&] (auto &parcel)
        {
            parcels.append(parcel);
        });

    // Act
    emit mockInterfaceSignalDataRecevied(bytesStr.toLatin1());

    // Assert
    QCOMPARE(parcels.count(), 1);
    QCOMPARE(parcels[0].getBytes(), payloadBtes.toLatin1());

    QObject::disconnect(this, SIGNAL(mockInterfaceSignalDataRecevied(QByteArray)), bytesParser, SLOT(onDataReceived(QByteArray)));
    delete bytesParser;
}

void TestTempHumSHT20ParserTest::parseBytes_ControlByteLost_ParserSkipsThisParcel()
{
    // Arrange
    QString bytesStr = "\rPAYLOAD BYTES\r\nPAYLOAD BYTES\r\n";

    QByteArray bytes = bytesStr.toLatin1();
    QSignalSpy spy(parser, SIGNAL(onParcelBuilt(const Parcel&)));

    // Act
    emit mockInterfaceSignalDataRecevied(bytes);

    // Assert
    QCOMPARE(spy.count(), 1);
}




QTEST_APPLESS_MAIN(TestTempHumSHT20ParserTest)

#include "TestTempHumSHT20Parser.moc"
