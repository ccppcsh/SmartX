#ifndef BASEDEVICE_H
#define BASEDEVICE_H

#include <QObject>
#include "Communication/BaseCommunicationInterface.h"

class BaseDevice : public QObject
{
    Q_OBJECT
public:
    explicit BaseDevice(BaseCommunicationInterface* comInterface, QObject *parent = nullptr);
    /**
     * @brief connect - tries to connect with device over communication interface
     */
    virtual void connect() = 0;
    /**
     * @brief disconnect - disconnects from device and disposes all used resources
     */
    virtual void disconnect() = 0;
    /**
     * @brief isConnected - returns status of device
     * @return - true, if connected; otherwise - false
     */
    virtual bool isConnected() = 0;
protected:
    BaseCommunicationInterface* mComInterface = NULL;
    bool mIsDeviceConnected = false;
signals:

public slots:
};

#endif // BASEDEVICE_H
