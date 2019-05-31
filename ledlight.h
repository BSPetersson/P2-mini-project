#ifndef LEDLIGHT_H
#define LEDLIGHT_H

#include <QObject>

class LEDLight
{
public:
    LEDLight();

    QStringList setColor(int, int, int);
    QStringList dead();
    QStringList river();
    QStringList forest();
    QStringList bear();
    QStringList bigOlSnakes();
    QStringList waterfall();
    QStringList win();
    QStringList white();
};

#endif // LEDLIGHT_H
