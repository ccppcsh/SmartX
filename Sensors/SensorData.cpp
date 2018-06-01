#include "SensorData.h"

SensorData::SensorData()
{

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
