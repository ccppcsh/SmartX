#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSerialPortInfo"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BaseSensor* baseSensor = new BaseSensor(this);

    auto sensorData = baseSensor->getSensorsDataList()[0];

    ui->lcdNumberTemp->display(sensorData.getValue());

    auto serialPorts = QSerialPortInfo::availablePorts();

    for (int i = 0; i < serialPorts.length(); i++)
    {
        ui->listWidget->addItem(serialPorts[i].portName());
    }

    ui->listWidget->addItem(QString(COM_PORT_NAME));
}

MainWindow::~MainWindow()
{
    delete ui;
}
