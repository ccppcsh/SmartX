#include "BaseSensor.h"

BaseSensor::BaseSensor(QObject *parent) : QObject(parent)
{

}

int BaseSensor::getValue()
{
    return 15;
}
