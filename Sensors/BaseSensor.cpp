#include "BaseSensor.h"

BaseSensor::BaseSensor(QObject *parent) : QObject(parent)
{
    mSensorsDataList.push_back(* (new SensorData(QString("Temperature"))));
    mSensorsDataList[0].setValue(35.4);
}

BaseSensor::BaseSensor(QString desc, QObject *parent): QObject(parent)
{
    mSensorDesc = desc;
}

const QList<SensorData> &BaseSensor::getSensorsDataList()
{
    return mSensorsDataList;
}

BaseSensor::SensorStatus BaseSensor::getSensorStatus()
{
    return mStatus;
}

void BaseSensor::setSensorDesc(QString desc)
{
    mSensorDesc = desc;
}

QString BaseSensor::getSensorDesc()
{
    return mSensorDesc;
}

