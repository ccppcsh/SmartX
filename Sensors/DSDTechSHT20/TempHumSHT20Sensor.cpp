#include "TempHumSHT20Sensor.h"

TempHumSHT20Sensor::TempHumSHT20Sensor(BaseCommunicationInterface* comInterface, QString desc, QObject* parent) :
    BaseSensor(comInterface, (BaseParser*) new TempHumSHT20Parser(), (BaseParcelHandler*) new TempHumSHT20ParcelHandler(), desc, parent)
{
    // Create sensor data
    mTemperature = new SensorData(QString("Temperature"));
    mHumidity = new SensorData(QString("Humidity"));

    mSensorsDataList.append(*mTemperature);
    mSensorsDataList.append(*mHumidity);
}

void TempHumSHT20Sensor::onParcelHandlerEvent(int event)
{
    TempHumSHT20ParcelHandler& handler = *((TempHumSHT20ParcelHandler *) mParcelHandler);

    // Handle events from parcel handler
    switch (event)
    {
        case (TempHumSHT20ParcelHandler::TEMPERATURE_VALUE_UPDATED):
            mTemperature->setValue(handler.getTempValue());
            mStatus = BaseSensor::SensorStatus::SENSOR_ACTIVE;
            emit sensorDataUpdated();
            break;
        case (TempHumSHT20ParcelHandler::HUMIDITY_VALUE_UPDATED):
            mHumidity->setValue(handler.getHumidityValue());
            mStatus = BaseSensor::SensorStatus::SENSOR_ACTIVE;
            emit sensorDataUpdated();
            break;
        case (TempHumSHT20ParcelHandler::PARCEL_NOT_RECOGNIZED):
            mStatus = BaseSensor::SensorStatus::SENSOR_ERROR_READ;
            emit sensorStatusChanged();
            break;
    }
}
