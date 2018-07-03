#include "BaseDevice.h"

BaseDevice::BaseDevice(BaseCommunicationInterface* comInterface, QObject *parent) : QObject(parent)
{
    mComInterface = comInterface;
}
