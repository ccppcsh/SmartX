#include "TempHumSHT20Sensor.h"

TempHumSHT20Sensor::TempHumSHT20Sensor(BaseCommunicationInterface* comInterface, QString desc, QObject* parent) :
    BaseSensor(comInterface, (BaseParser*) new TempHumSHT20Parser(), (BaseParcelHandler*) new TempHumSHT20ParcelHandler(), desc, parent)
{

}
