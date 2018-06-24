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

void TestTempHumSHT20ParserTest::parseBytes_ValidParcel_onParcelBuiltEmited()
{
    // Arrange
    QByteArray bytes = QByteArray("\r\nPAYLOAD BYTES\r\n");
    QSignalSpy spy(parser, SIGNAL(onParcelBuilt(Parcel&)));

    // Act
    emit mockInterfaceSignalDataRecevied(bytes);

    // Assert
    QCOMPARE(spy.count(), 1);
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
