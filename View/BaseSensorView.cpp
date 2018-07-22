#include "BaseSensorView.h"


BaseSensorView::BaseSensorView(BaseSensor *sensor)
{
    mSensor = sensor;

    // Setup layout
    this->setSpacing(0);
    this->setMargin(0);
    this->setAlignment(Qt::AlignTop);


    // Add label description
    QLabel* pLabelDesc = new QLabel();
    pLabelDesc->setText(mSensor->getSensorDesc()); 
    this->addWidget(pLabelDesc, 0, Qt::AlignTop);


    /*QLabel* pLabelDescTest = new QLabel();
    pLabelDescTest->setText(mSensor->getSensorDesc());
    this->addWidget(pLabelDescTest, 0, Qt::AlignTop);*/

    // Add spacer
    QFrame* line = new QFrame();
    line->setObjectName(QString::fromUtf8("line"));
    line->setGeometry(QRect(320, 150, 118, 3));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    this->addWidget(line, 0, Qt::AlignTop);

    auto sensorList = mSensor->getSensorsDataList();
    for (int i = 0; i < sensorList.length(); i++)
    {
        addSensorValueChart(sensorList[i].getName());
    }
}

void BaseSensorView::addSensorValueChart(QString desc)
{
    ChartSensorView* chart = new ChartSensorView();
    chart->setTitle(desc);
    chart->setAnimationOptions(QChart::AllAnimations);

     QChartView* chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);

     this->addWidget(chartView);
}
