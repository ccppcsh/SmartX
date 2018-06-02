#include "SerialInterface.h"

SerialInterface::SerialInterface(QString portName, QObject *parent) : BaseCommunicationInterface(parent)
{
    mPortName = portName;
}

bool SerialInterface::connect(int baudrate)
{

}

bool SerialInterface::disconnect()
{

}

int SerialInterface::send(const QList<uint8_t> &bytes)
{

}

bool SerialInterface::isConnected()
{

}
