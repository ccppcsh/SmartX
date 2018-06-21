#ifndef BASESENSOR_H
#define BASESENSOR_H

#include <QObject>
#include "SensorData.h"

class BaseSensor : public QObject
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
    BaseSensor(QString desc, QObject *parent);
    const QList<SensorData>& getSensorsDataList();
    BaseSensor::SensorStatus getSensorStatus();
    void setSensorDesc(QString desc);
    QString getSensorDesc();
private:
    QList<SensorData> mSensorsDataList = QList<SensorData>();
    BaseSensor::SensorStatus mStatus = SensorStatus::SENSORE_INACTIVE;
    QString mSensorDesc = "";

signals:

public slots:
};



#endif // BASESENSOR_H
