#include <QString>
#include <QtTest>
#include "Sensors/DSDTechSHT20/TempHumSHT20Parser.h"

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
    QTest::addColumn<QString>("bytesStr");
    QTest::addColumn<int>("cntParcelExpected");

    QTest::newRow("One parcel inside") << "\r\n\PAYLOAD DATA\r\n" << 1;
    QTest::newRow("One parcel inside with trash before") << "TRASH\r\n\PAYLOAD DATA\r\n" << 1;
    QTest::newRow("Three parcel inside") << "\r\n\PAYLOAD DATA #1\r\nPAYLOAD DATA #2\r\nPAYLOAD DATA #3\r\n" << 3;
}

void TestTempHumSHT20ParserTest::parseBytes_ValidParcel_onParcelBuiltEmited()
{
    //QString bytesStr;
    //int parcelCnt;
    QFETCH(QString, bytesStr);
    QFETCH(int, cntParcelExpected);

    // Arrange
    //QByteArray bytes = QByteArray("\r\nPAYLOAD BYTES\r\n");
    QByteArray bytes = bytesStr.toLatin1();
    QSignalSpy spy(parser, SIGNAL(onParcelBuilt(Parcel&)));

    // Act
    emit mockInterfaceSignalDataRecevied(bytes);

    // Assert
    QCOMPARE(spy.count(), cntParcelExpected);
}

void TestTempHumSHT20ParserTest::parseBytes_ValidParcel_ParsedCorrect()
{
    QVERIFY2(true, "Failure");
}

void TestTempHumSHT20ParserTest::parseBytes_ControlByteLost_ParserSkipsThisParcel()
{
    QVERIFY2(true, "Failure");
}




QTEST_APPLESS_MAIN(TestTempHumSHT20ParserTest)

#include "TestTempHumSHT20Parser.moc"
