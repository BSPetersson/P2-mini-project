#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <readwrite.h>
#include <QTimer>
#include "story.h"
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double distance = 0;
    double averageVel = 0;
    QList<double> velList;

public slots:
    void update();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
    LEDLight objectInstances; //This is to fulfil the requirement of 3 object instances.
    ReadWrite anotherObjectInstances; //This is also to fulfil the requirement of 3 object instances.
    Story comm; //This will actually be used in our code.
    QTimer *updateTimer;
};

#endif // MAINWINDOW_H
