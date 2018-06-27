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

void TempHumSHT20ParcelHandler::handleParcel(const Parcel &parcel)
{
    // The received parcel should look like this: "Temp=26.170 Humi=51.240"

    // Convert the payload bytes to string
    const QByteArray& bytes = parcel.getBytes();
    QString bytesStr = QString(bytes);
    // Search for substring TEMP and HUM in the parcel
    int posFirstEqualChar = bytesStr.indexOf('=');
    int posWhiteSpaceChar = bytesStr.indexOf(' ');
    int posSecondEqualChar = bytesStr.lastIndexOf('=');

    // If not found - emit error
    if ((posFirstEqualChar == -1) || (posWhiteSpaceChar == -1) || (posSecondEqualChar == -1) || (posFirstEqualChar == posSecondEqualChar))
    {
        emit eventOccured(PARCEL_NOT_RECOGNIZED);
        return;
    }

    // Get values and try to convert it into values
    QString tempStr = bytesStr.mid(posFirstEqualChar + 1, posWhiteSpaceChar - posFirstEqualChar - 1);
    QString humiStr = bytesStr.mid(posSecondEqualChar + 1, bytesStr.length() - posSecondEqualChar - 1);

    bool isConverted = false;

    mTemperatureValue = tempStr.toFloat(&isConverted);

    if (isConverted == false)
    {
        emit eventOccured(PARCEL_NOT_RECOGNIZED);
        return;
    }
    else
    {
        emit eventOccured(TEMPERATURE_VALUE_UPDATED);
    }

    mHumidityValue = humiStr.toFloat(&isConverted);

    if (isConverted == false)
    {
        emit eventOccured(PARCEL_NOT_RECOGNIZED);
        return;
    }
    else
    {
        emit eventOccured(HUMIDITY_VALUE_UPDATED);
    }

}
