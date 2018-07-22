#ifndef CHARTSENSORVIEW_H
#define CHARTSENSORVIEW_H

/**
 * @file    ChartSensorView.h
 * @date    2018-07-22
 * @author  sauber
 * @brief   The ChartSensorView class header file
 * Creates a chart for a sensor.
 */

#include <QtCharts/QChart>


QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class ChartSensorView : public QChart
{
    Q_OBJECT
public:
    ChartSensorView(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
public slots:
    //void valueUpdated();
private:
    QSplineSeries* mSerie;
    QStringList mTitles;
    QValueAxis* mAxis;

};

#endif // CHARTSENSORVIEW_H
