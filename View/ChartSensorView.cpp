#include "ChartSensorView.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>


ChartSensorView::ChartSensorView(QChartView* parentChart, QString title, QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags)
{
    mParentChart = parentChart;
    mTitle = title;

    mSerie = new QSplineSeries(this);
    QPen pen(Qt::red);
    pen.setWidth(1);

    mSerie->setPen(pen);

    addSeries(mSerie);
    createDefaultAxes();
    this->legend()->hide();

    mAxisX = new QValueAxis();
    mAxisY = new QValueAxis();
    setAxisX(mAxisX, mSerie);
    setAxisY(mAxisY, mSerie);

    axisX()->setRange(0, 24);
    axisY()->setRange(0, 100);

    this->setTitle(mTitle);

    /*this->addValue(12.5);
    this->addValue(13.5);
    this->addValue(14.5);
    this->addValue(15.5);
    this->addValue(16.5);
    this->addValue(17.5);
    this->addValue(12.5);*/
}

void ChartSensorView::addValue(float value)
{
    // Check current time, if it's a new day - reset all values
    if ( QTime::currentTime() < mLastTimeStamp)
    {
        this->series().clear();
        mMaxY = std::numeric_limits<qreal>::min();
        mMinY = std::numeric_limits<qreal>::max();
    }

    this->setTitle(mTitle + " [" + QString::number(value) + " " + mUnit + "]");
    mLastTimeStamp = QTime::currentTime();
    mSerie->append((qreal) mLastTimeStamp.hour() + (qreal) mLastTimeStamp.minute() / 60.0, value);

    if (value > mMaxY)
        mMaxY = value;
    if (value < mMinY)
        mMinY = value;

    //Adjust sensor values range
    int min = (int) (mMinY * 0.8);
    int max = (int) (mMaxY * 1.2);
    axisY()->setRange(min, max);
}

void ChartSensorView::setUnit(QString unit)
{
    mUnit = unit;
}
