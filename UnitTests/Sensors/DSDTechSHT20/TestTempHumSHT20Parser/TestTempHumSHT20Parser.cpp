#include <QString>
#include <QtTest>

class TestTempHumSHT20Parser : public QObject
{
    Q_OBJECT

public:
    TestTempHumSHT20Parser();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

TestTempHumSHT20Parser::TestTempHumSHT20Parser()
{
}

void TestTempHumSHT20Parser::initTestCase()
{
}

void TestTempHumSHT20Parser::cleanupTestCase()
{
}

void TestTempHumSHT20Parser::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestTempHumSHT20Parser)

#include "TestTempHumSHT20Parser.moc"
