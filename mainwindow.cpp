#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BaseSensor* baseSensor = new BaseSensor(this);

    auto sensorData = baseSensor->getSensorsDataList()[0];

    ui->lcdNumberTemp->display(sensorData.getValue());
}

MainWindow::~MainWindow()
{
    delete ui;
}
