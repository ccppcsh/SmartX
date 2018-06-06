#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include "BaseCommunicationInterface.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QException>

class SerialInterface : public BaseCommunicationInterface
{
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
    QSerialPort* mCOMPort;
    bool mIsConnected = false;
};

#endif // SERIALINTERFACE_H
