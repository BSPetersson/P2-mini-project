#ifndef READWRITE_H
#define READWRITE_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QObject>

class ReadWrite: public QObject
{

    Q_OBJECT
public:
    ReadWrite();
    ~ReadWrite();

    QString arduinoPortName();
    bool arduinoIsAvailable();
    void read();
    void setup();
    void sendMessage(QString);
    QString getButtonStatus();

    QStringList buttonMessage;
    QSerialPort *arduino;

    bool initializer = false;
    QStringList bufferSplit;
    QStringList messageArray;

    QString message;
    int leftButMessage;
    int rightButMessage;
    double vel;
    int storyDone;
    QString DFPlayerStatus;


public slots:
    void readSerial();


private:

    bool arduino_is_available;
    static const quint16 arduino_uno_vendor_id = 10755;
    static const quint16 arduino_uno_product_id = 67;
    QString port_name;
    QString serialBuffer;


};

#endif // READWRITE_H
