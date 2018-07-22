#include "ChartSensorView.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>

ChartSensorView::ChartSensorView(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
    mSerie = new QSplineSeries(this);
    QPen pen(Qt::red);
    pen.setWidth(3);

    mSerie->setPen(pen);

    addSeries(mSerie);
    createDefaultAxes();
    this->legend()->hide();

    mAxis = new QValueAxis();
    setAxisX(mAxis, mSerie);

    axisX()->setRange(0, 10);
    axisY()->setRange(0, 10);
    mSerie->append(5, 6);
    mSerie->append(6, 7);
    mSerie->append(7, 8);
    mSerie->append(8, 9);
    mSerie->append(9, 10);
}
