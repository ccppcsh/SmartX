#ifndef BASESENSOR_H
#define BASESENSOR_H

/**
 * @file    BaseSensor.h
 * @date    2018-07-03
 * @author  sauber
 * @brief   The BaseSensor class header file
 */

#include <QObject>
#include "SensorData.h"
#include "Device/BaseDevice.h"
#include "ProtocolParser/BaseParcelHandler.h"
#include "ProtocolParser/BaseParser.h"

class BaseSensor : public BaseDevice
{
    Q_OBJECT
public:
    enum SensorStatus{
        SENSOR_ACTIVE,
        SENSORE_INACTIVE,
        SENSOR_ERROR_READ,
        SENSOR_OK
    };
    explicit BaseSensor(QObject *parent);
    BaseSensor(BaseCommunicationInterface* comInterface, BaseParser* parser, BaseParcelHandler* handler, QString desc = "", QObject *parent = NULL);
    ~BaseSensor();
    /**
     * @brief getSensorsDataList - returns a list with all values of sensor
     * @return - list with all sensor values
     */
    const QList<SensorData>& getSensorsDataList();
    /**
     * @brief getSensorStatus - return current status of sensor
     * @return - sensor status
     */
    BaseSensor::SensorStatus getSensorStatus();
    /**
     * @brief setSensorDesc - sets a description of sensor
     * @param desc - string which contains sensor description
     */
    void setSensorDesc(QString desc);
    /**
     * @brief getSensorDesc - returns a description of sensor
     * @return - string with description
     */
    QString getSensorDesc() const;
private:
    QString mSensorDesc = "";
    BaseParcelHandler* mParcelHandler = NULL;
    BaseParser* mParser = NULL;
protected:
    QList<SensorData> mSensorsDataList = QList<SensorData>();
    BaseSensor::SensorStatus mStatus = SensorStatus::SENSORE_INACTIVE;

    /**
     * @brief connect - tries to connect with device over communication interface
     */
    virtual void connect();
    /**
     * @brief disconnect - disconnects from device and disposes all used resources
     */
    virtual void disconnect();
    /**
     * @brief isConnected - returns status of device
     * @return - true, if connected; otherwise - false
     */
    virtual bool isConnected();

signals:
    void sensorDataUpdated();
    void sensorStatusChanged();
public slots:
    /**
     * @brief onParcelHandlerEvent - sensor specific handler by handling a parcel
     * @param event - type of event which is defined for each implemented sensor
     */
    virtual void onParcelHandlerEvent(int event) = 0;
};



#endif // BASESENSOR_H
