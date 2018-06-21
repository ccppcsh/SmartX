#include "TempHumSHT20ParcelHandler.h"

/**
 * @file    TempHumSHT20ParcelHandler.h
 * @date    2018-06-21
 * @author  sauber
 * @brief   The TempHumSHT20ParcelHandler class implementation file. This class will handle received built parcels for sensor
 * DSDTech SHT20.
 */


TempHumSHT20ParcelHandler::TempHumSHT20ParcelHandler()
{

}

float TempHumSHT20ParcelHandler::getTempValue()
{
    return mTemperatureValue;
}

float TempHumSHT20ParcelHandler::getHumidityValue()
{
    return mHumidityValue;
}

void TempHumSHT20ParcelHandler::handleParcel(Parcel &parcel)
{
    // Convert the payload bytes to string

    // Search for substring TEMP and HUM in the parcel

    // Get values and try to convert it into values
}
