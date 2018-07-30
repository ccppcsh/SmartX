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
#include <QtCharts/QChartView>
#include <QTime>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class ChartSensorView : public QChart
{
    Q_OBJECT
public:
    ChartSensorView(QChartView* parentChart, QString title, QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    /**
     * @brief addValue - adds a new value to chart
     * @param value - value to add
     */
    void addValue(float value);
    /**
     * @brief setUnit - add units to measured value
     * @param unit - unit to display
     */
    void setUnit(QString unit);
public slots:
    //void valueUpdated();
private:
    QSplineSeries* mSerie;
    QStringList mTitles;
    QValueAxis* mAxisX;
    QValueAxis* mAxisY;
    QString mUnit = "";
    QString mTitle = "";
    QChartView* mParentChart = NULL;
    QTime mLastTimeStamp;
    qreal mMaxY = std::numeric_limits<qreal>::min();
    qreal mMinY = std::numeric_limits<qreal>::max();
};

#endif // CHARTSENSORVIEW_H
