#include "readwrite.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include <QObject>

ReadWrite::ReadWrite() {
    arduino = new QSerialPort;


}

ReadWrite::~ReadWrite(){

    if(arduino->isOpen()){
        arduino->close();
    }

}


void ReadWrite::read(){
    QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
}


void ReadWrite::sendMessage(QString message){
    if (arduino->isWritable()){
        arduino->write(message.toStdString().c_str());
        qDebug() << QString("Sending message: %1").arg(message);
    }
    else {
        qDebug("Could not write to arduino already");
    }

}



void ReadWrite::setup(){

    if(arduinoIsAvailable()){
        //Open and configure the port
        arduino->setPortName(arduinoPortName());
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
    }

    initializer = true;
}

QString ReadWrite::arduinoPortName(){
    arduino_is_available = false;
    port_name = "";

    serialBuffer = "";

    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_product_id){}
                port_name = serialPortInfo.portName();
                arduino_is_available = true;
            }
        }
    }

    return port_name;
}

bool ReadWrite::arduinoIsAvailable(){


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Has vendor ID:" << serialPortInfo.hasVendorIdentifier();
        if (serialPortInfo.hasVendorIdentifier()) {
            qDebug() << "Vendor ID:" << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has product ID:" << serialPortInfo.hasProductIdentifier();
        if (serialPortInfo.hasProductIdentifier()) {
            qDebug() << "Product ID:" << serialPortInfo.productIdentifier();
        }

    if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
                if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id) {
                    if(serialPortInfo.productIdentifier() == arduino_uno_product_id) {
                        port_name = serialPortInfo.portName();
                        arduino_is_available = true;
                    }
                }
            }

        }
    return arduino_is_available;
}

void ReadWrite::readSerial(){

    QByteArray serialData = ReadWrite::arduino->readAll();
    serialBuffer += QString::fromStdString(serialData.toStdString());

    QStringList bufferSplit = serialBuffer.split("-");


    if(bufferSplit.length() > 1){

        QStringList message = bufferSplit.at(0).split(",");

        if (message.length() == 5) {
            leftButMessage = message.at(0).toInt();
            rightButMessage = message.at(1).toInt();
            vel = message.at(2).toDouble() / 100;
            storyDone = message.at(3).toInt();
            DFPlayerStatus = message.at(4);
        }

    serialBuffer = "";
    }
}

QString ReadWrite::getButtonStatus(){
bool left = leftButMessage;
bool right = rightButMessage;

    if(right && left){
    return "You went both";
    }
    if(!right && !left){
    return "You went neither";
    }
    if(right && !left){
    return "You went right";
    }
    if(!right && left){
    return "You went left";
    }

    return "nothing Major fail by us";
}
