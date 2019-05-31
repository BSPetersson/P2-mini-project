#include "ledlight.h"
#include <QObject>

LEDLight::LEDLight() {

}

QStringList LEDLight::dead() {
    QStringList RGBMessage = { "r255", "g0", "b0" };
    return RGBMessage;
}

QStringList LEDLight::river(){
    QStringList RGBMessage = { "r0", "g100", "b255" };
    return RGBMessage;
}

QStringList LEDLight::forest(){
    QStringList RGBMessage = { "r0", "g255", "b0" };
    return RGBMessage;
}

QStringList LEDLight::bear(){
    QStringList RGBMessage = { "r150", "g30", "b0" };
    return RGBMessage;
}

QStringList LEDLight::bigOlSnakes(){
    QStringList RGBMessage = { "r255", "g255", "b0" };
    return RGBMessage;
}

QStringList LEDLight::waterfall(){
    QStringList RGBMessage = { "r0", "g0", "b255" };
    return RGBMessage;
}

QStringList LEDLight::win(){
    QStringList RGBMessage = { "r0", "g255", "b255" };
    return RGBMessage;
}

QStringList LEDLight::white(){
    QStringList RGBMessage = { "r255", "g255", "b255" };
    return RGBMessage;
}
