#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include "BaseCommunicationInterface.h"
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialInterface : public BaseCommunicationInterface
{
public:
    explicit SerialInterface(QString portName, QObject *parent = nullptr);
    virtual bool connect(int baudrate);
    virtual bool disconnect();
    virtual int send(const QList<uint8_t>& bytes);
    virtual bool isConnected();
private:
    QString mPortName;
};

#endif // SERIALINTERFACE_H
