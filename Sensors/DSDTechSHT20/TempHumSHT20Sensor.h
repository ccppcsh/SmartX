#ifndef TEMPHUMSHT20SENSOR_H
#define TEMPHUMSHT20SENSOR_H

#include "Sensors/BaseSensor.h"
#include "Sensors/DSDTechSHT20/TempHumSHT20ParcelHandler.h"
#include "Sensors/DSDTechSHT20/TempHumSHT20Parser.h"

class TempHumSHT20Sensor : public BaseSensor
{
public:
    TempHumSHT20Sensor(BaseCommunicationInterface* comInterface, QString desc, QObject* parent = NULL);
};

#endif // TEMPHUMSHT20SENSOR_H
