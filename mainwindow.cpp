#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSerialPortInfo"
#include "Communication/SerialInterface.h"
#include "View/BaseSensorView.h"
#include "Sensors/DSDTechSHT20/TempHumSHT20Sensor.h"

SerialInterface* comPort;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //BaseSensor* baseSensor = new BaseSensor(this);

    //auto sensorData = baseSensor->getSensorsDataList()[0];

    //ui->lcdNumberTemp->display(sensorData.getValue());

    comPort = new SerialInterface(COM_PORT_NAME, 115200);
    //comPort->connect();

    /*QByteArray bytes = QByteArray();
    bytes.append(5, 'A');

    comPort->send(bytes);*/

    TempHumSHT20Sensor* sensor = new TempHumSHT20Sensor(comPort, "Temperature and humididty sensor");
    BaseSensorView* sensorView = new BaseSensorView(sensor);

    ui->vboxSensors->setSpacing(0);
    ui->vboxSensors->setMargin(0);
    ui->vboxSensors->addLayout(sensorView);

    // TEST
    /*QLabel* pLabelDesc = new QLabel();
    this->ui->verticalLayout->setSpacing(0);
    this->ui->verticalLayout->setContentsMargins(0, 0, 0, 0);
    this->ui->verticalLayout->setAlignment(Qt::AlignTop);
    pLabelDesc->setText(QString("Test1"));
    pLabelDesc->setContentsMargins(-1, -1, -1, 0);
    pLabelDesc->setFrameShape(QFrame::NoFrame);
    pLabelDesc->setLineWidth(0);
    pLabelDesc->setFixedHeight(20);
    pLabelDesc->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    this->ui->verticalLayout->addWidget(pLabelDesc);

    pLabelDesc = new QLabel();

    pLabelDesc->setText(QString("Test2"));
    pLabelDesc->setContentsMargins(-1, -1, -1, 0);
    pLabelDesc->setFrameShape(QFrame::NoFrame);
    pLabelDesc->setLineWidth(0);
    pLabelDesc->setFixedHeight(20);
    pLabelDesc->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

     this->ui->verticalLayout->addWidget(pLabelDesc);*/


}

MainWindow::~MainWindow()
{
    comPort->disconnect();
    delete ui;
}
