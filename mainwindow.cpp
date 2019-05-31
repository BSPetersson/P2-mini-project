#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include "readwrite.h"
#include "QTimer"
#include "QList"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->volumeLable->setText(QString("%1").arg(100));

    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    updateTimer->start(300);

    comm.setup();
    qDebug() << "wait for 5 seconds before booting to wait for Arduino";
    QThread::sleep(5);


    if(comm.initializer == true){
        comm.read();
        qDebug() << "read loaded";
        comm.sendMessage(QString("v100"));
        comm.sendMessage(QString("s%1").arg(comm.place));
        comm.actions(comm.place);
    }

}

MainWindow::~MainWindow() {
    if(arduino->isOpen()){
            arduino->close();
        }
    delete ui;
}

void MainWindow::update() {
    comm.next();
    velList.append(comm.vel);

    double totalVel = 0;
    for (int i = 0; i < velList.length(); i++) {
        totalVel += velList.at(i);
    }
    averageVel = totalVel/velList.length();

    distance += comm.vel * 0.08333; //300/1000/60/60 * 1000

    ui->speedLable->setText(QString("%1").arg(comm.vel));
    ui->averageSpeedLable->setText(QString("%1").arg(averageVel));
    ui->distanceLable->setText(QString("%1").arg(distance));
    ui->infoLable->setText(comm.DFPlayerStatus);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->volumeLable->setText(QString("%1").arg(value));
    comm.sendMessage(QString("v%1").arg(value));
}
