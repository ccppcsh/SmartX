#ifndef BASESENSORVIEW_H
#define BASESENSORVIEW_H
/**
 * @file    BaseSensor.h
 * @date    2018-07-020
 * @author  sauber
 * @brief   The BaseSensorView class header file
 * This class displays the current values of sensors. The sensors data will be displayed on QChart like a time-graphic wit hcurrent value.
 */

//QT Includes
#include <QVBoxLayout>
#include <QtCharts/QChartView>
#include <QLabel>

//SmartX includes
#include "Sensors/BaseSensor.h"
#include "ChartSensorView.h"

class BaseSensorView : public QVBoxLayout
{
public:
    BaseSensorView(BaseSensor* sensor);
private:
    BaseSensor* mSensor;
    /**
     * @brief addSensorValueChart - generates sensor chart view for sensor parameter
     * @param desc - name of measured parameter by sensor
     */
    void addSensorValueChart(QString desc);
};

#endif // BASESENSORVIEW_H
