#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    BaseSensor* baseSensor = new BaseSensor(this);


    ui->lcdNumberTemp->display(baseSensor->getValue());
}

MainWindow::~MainWindow()
{
    delete ui;
}
