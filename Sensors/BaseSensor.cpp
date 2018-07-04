/**
 * @file    BaseSensor.h
 * @date    2018-07-03
 * @author  sauber
 * @brief   The BaseSensor implementation class file
 */

#include "BaseSensor.h"

BaseSensor::BaseSensor(QObject *parent) : BaseDevice(NULL, parent)
{

}

BaseSensor::BaseSensor(BaseCommunicationInterface *comInterface, BaseParser *parser, BaseParcelHandler *handler, QString desc, QObject *parent) : BaseDevice(comInterface, parent)
{

    mParcelHandler = handler;
    mParser = parser;
    mSensorDesc = desc;
    if ((mParser == NULL) || (mParcelHandler == NULL) || (mComInterface == NULL))
    {
        // TODO: Error handling
    }

    // Connect signals and slots
    // Interface --> Parser --> ParcelHandler --> Sensor
    QObject::connect(mComInterface, SIGNAL(onDataReceived(QByteArray)), mParser, SLOT(onDataReceived(QByteArray)));
    QObject::connect(mParser, SIGNAL(onParcelBuilt(Parcel)), mParcelHandler, SLOT(onParcelBuilt(Parcel)));
    QObject::connect(mParcelHandler, SIGNAL(eventOccured(int)), this, SLOT(onParcelHandlerEvent));
}

BaseSensor::~BaseSensor()
{
    if (mComInterface != NULL)
        mComInterface->disconnect();

    QObject::disconnect(mComInterface, SIGNAL(onDataReceived(QByteArray)), mParser, SLOT(onDataReceived(QByteArray)));
    QObject::disconnect(mParser, SIGNAL(onParcelBuilt(Parcel)), mParcelHandler, SLOT(onParcelBuilt(Parcel)));
    QObject::disconnect(mParcelHandler, SIGNAL(eventOccured(int)), this, SLOT(onParcelHandlerEvent));

    delete mComInterface;
    delete mParser;
    delete mParcelHandler;
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

QString BaseSensor::getSensorDesc() const
{
    return mSensorDesc;
}

void BaseSensor::connect()
{
    auto ec = mComInterface->connect();

    if (ec == BaseCommunicationInterface::ErrorCode::OK)
        mIsDeviceConnected = true;
    else
        mIsDeviceConnected = false;

    return;
}

void BaseSensor::disconnect()
{
    mComInterface->disconnect();

    mIsDeviceConnected = false;
}

bool BaseSensor::isConnected()
{
    return mIsDeviceConnected;
}

