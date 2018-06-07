#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSerialPortInfo"
#include "Communication/SerialInterface.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BaseSensor* baseSensor = new BaseSensor(this);

    auto sensorData = baseSensor->getSensorsDataList()[0];

    ui->lcdNumberTemp->display(sensorData.getValue());

    SerialInterface* comPort = new SerialInterface(COM_PORT_NAME, 115200);
    comPort->connect();

    QByteArray bytes = QByteArray();
    bytes.append(5, 'A');

    comPort->send(bytes);

    comPort->disconnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}
