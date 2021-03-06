#ifndef SENSORVALUE_H
#define SENSORVALUE_H

#include <QObject>

class SensorData
{
public:
    SensorData(QString name);
    float getValue();
    QString getName();
    void setValue(float value);
private:
    float mValue;
    QString mName;
};


#endif // SENSORVALUE_H
