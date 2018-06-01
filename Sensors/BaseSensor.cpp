#include "BaseSensor.h"

BaseSensor::BaseSensor(QObject *parent) : QObject(parent)
{
    mSensorsDataList.push_back(* (new SensorData(QString("Temperature"))));
    mSensorsDataList[0].setValue(35.4);
}

const QList<SensorData> &BaseSensor::getSensorsDataList()
{
    return mSensorsDataList;
}

BaseSensor::SensorStatus BaseSensor::getSensorStatus()
{
    return mStatus;
}

