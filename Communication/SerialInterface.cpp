#include "SerialInterface.h"

SerialInterface::SerialInterface(QString portName, int baudrate, QObject *parent) : BaseCommunicationInterface(parent)
{
    mPortName = portName;
    mBaudrate = baudrate;

    mCOMPort = new QSerialPort();
}

/**
 * @brief SerialInterface::connect - tries to open COM port with parameters defined in constructor
 * @return ErrorCode - OK, if the port was successfully opened; otherwise - error code.
 */
BaseCommunicationInterface::ErrorCode SerialInterface::connect()
{
    auto availablePorts = QSerialPortInfo::availablePorts();
    bool isPortAvailable = false;

    // Check that this port is available for connect
    for (int i = 0; i < availablePorts.length(); i++)
    {
        if (availablePorts[i].portName() == mPortName)
        {
            isPortAvailable = true;
            break;
        }
    }

    if (isPortAvailable != true)
        return INTERFACE_NOT_AVAILABLE;

    if ((mBaudrate <= 1) && (mBaudrate > 230000))
    {
        return WRONG_INTERFACE_PARAMETERS;
    }
    // Check, that this port name is available for connect
    mCOMPort->setPortName(mPortName);

    // Check. that this baudarate is more than 0 and less than 230000
    mCOMPort->setBaudRate(mBaudrate);
    mCOMPort->setDataBits(QSerialPort::Data8);
    mCOMPort->setStopBits(QSerialPort::OneStop);

    auto openResult = mCOMPort->open(QIODevice::ReadWrite);

    if (openResult)
    {
        mIsConnected = true;
        return OK;
    }
    else
    {
        mIsConnected = false;
        return ERROR_BY_OPEN_PORT;
    }
}

/**
 * @brief SerialInterface::disconnect - closes the opened connection
 * @return ErrorCode - OK, if port was closed; otherwise - error code
 */
BaseCommunicationInterface::ErrorCode SerialInterface::disconnect()
{
    mCOMPort->close();

    return OK;
}

/**
 * @brief SerialInterface::send - tries to send a list with bytes over COM Port
 * @param bytes - list with bytes to send
 * @return ErrorCode - OK, if all data was sent; otherwise - error code
 */
BaseCommunicationInterface::ErrorCode SerialInterface::send(const QByteArray& bytes)
{
    // check, that port is connected
    if (!mIsConnected)
        return INTERFACE_IS_NOT_CONNECTED;

    if ( mCOMPort->write(bytes) == -1)
    {
        return ERROR_BY_SENDING_DATA;
    }
    mCOMPort->flush();

    return OK;
}

/**
 * @brief SerialInterface::isConnected - returns the current state of port
 * @return true - if port is connected; else - false
 */
bool SerialInterface::isConnected()
{
    return mIsConnected;
}

SerialInterface::~SerialInterface()
{
    mCOMPort->close();
    delete mCOMPort;
}
