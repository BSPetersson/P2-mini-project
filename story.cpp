#include "story.h"
#include <QtWidgets>

Story::Story() {

}

void Story::next() {
    if (storyDone) {
        storyDone = false;
        if (place == 14) {
            place = storyLine[place-1][2];
            sendMessage(QString("s%1").arg(place));
            actions(place);
        } else if (place == 6) {
             if (rightButMessage && !leftButMessage) {
               place = storyLine[place-1][2];
               sendMessage(QString("s%1").arg(place));
               actions(place);
             } else if (vel < 5) {
               place = storyLine[place-1][1];
               sendMessage(QString("s%1").arg(place));
               actions(place);
             } else {
               place = storyLine[place-1][0];
               sendMessage(QString("s%1").arg(place));
               actions(place);
             }
           } else if (place == 2) {
             if (vel < 5) {
               place = storyLine[place-1][0];
               sendMessage(QString("s%1").arg(place));
               actions(place);
             } else {
               place = storyLine[place-1][1];
               sendMessage(QString("s%1").arg(place));
               actions(place);
             }
        } else if (leftButMessage && !rightButMessage) {
             place = storyLine[place-1][0];
             sendMessage(QString("s%1").arg(place));
             actions(place);
           } else if (rightButMessage && !leftButMessage) {
             place = storyLine[place-1][1];
             sendMessage(QString("s%1").arg(place));
             actions(place);
           }
    }
}

void Story::actions(int storyIndex) {
     QStringList RGBMessage = { "r255", "g255", "b255" };
  switch(storyIndex) {
    case 1:
      RGBMessage = forest();
    break;
    case 2:
      RGBMessage = waterfall();
    break;
    case 3:
      RGBMessage = dead();
    break;
    case 4:
      RGBMessage = forest();
    break;
    case 5:
      RGBMessage = forest();
    break;
    case 6:
      RGBMessage = bear();
    break;
    case 7:
      RGBMessage = dead();
    break;
    case 8:
      RGBMessage = bigOlSnakes();
    break;
    case 9:
      RGBMessage = dead();
    break;
    case 10:
      RGBMessage = win();
    break;
    case 11:
      RGBMessage = river();
    break;
    case 12:
      RGBMessage = forest();
    break;
    case 13:
      RGBMessage = white();
    break;
  }
  sendMessage(QString(RGBMessage.at(0)));
  sendMessage(QString(RGBMessage.at(1)));
  sendMessage(QString(RGBMessage.at(2)));
}
