#ifndef TEMPHUMSHT20SENSOR_H
#define TEMPHUMSHT20SENSOR_H

#include "Sensors/BaseSensor.h"
#include "Sensors/DSDTechSHT20/TempHumSHT20ParcelHandler.h"
#include "Sensors/DSDTechSHT20/TempHumSHT20Parser.h"

class TempHumSHT20Sensor : public BaseSensor
{
public:
    TempHumSHT20Sensor(BaseCommunicationInterface* comInterface, QString desc, QObject* parent = NULL);
private:
    SensorData* mTemperature;
    SensorData* mHumidity;
public slots:
    /**
     * @brief onParcelHandlerEvent - sensor specific handler by handling a parcel
     * @param event - type of event which is defined for each implemented sensor
     */
    virtual void onParcelHandlerEvent(int event);
};

#endif // TEMPHUMSHT20SENSOR_H
