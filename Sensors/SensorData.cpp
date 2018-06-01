#include "SensorData.h"

SensorData::SensorData(QString name)
{
    mName = name;
}

float SensorData::getValue()
{
    return mValue;
}

QString SensorData::getName()
{
    return mName;
}

void SensorData::setValue(float value)
{
    mValue = value;
}
