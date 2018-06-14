#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include "BaseCommunicationInterface.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QException>

class SerialInterface : public BaseCommunicationInterface
{
    Q_OBJECT
public:
    explicit SerialInterface(QString portName, int baudrate, QObject *parent = nullptr);
    virtual ErrorCode connect();
    virtual ErrorCode disconnect();
    virtual ErrorCode send(const QByteArray& bytes);
    virtual bool isConnected();
    virtual ~SerialInterface();
private:
    QString mPortName;
    int mBaudrate;
    QSerialPort* mCOMPort = NULL;
    bool mIsConnected = false;
public slots:
    void dataReceived();
};

#endif // SERIALINTERFACE_H
