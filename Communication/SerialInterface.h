#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include "BaseCommunicationInterface.h"
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialInterface : public BaseCommunicationInterface
{
public:
    explicit SerialInterface(QObject *parent = nullptr);
    virtual void connect();
    virtual void disconnect();
    virtual void send(const QList<uint8_t>& bytes);
    virtual void isConnected();
};

#endif // SERIALINTERFACE_H
