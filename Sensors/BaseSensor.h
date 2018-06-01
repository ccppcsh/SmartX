#ifndef BASESENSOR_H
#define BASESENSOR_H

#include <QObject>
#include "SensorData.h"

class BaseSensor : public QObject
{
    Q_OBJECT
public:
    explicit BaseSensor(QObject *parent);
    const QList<SensorData>& getSensorsDataList();
private:
    QList<SensorData> mSensorsDataList = QList<SensorData>();
signals:

public slots:
};



#endif // BASESENSOR_H
