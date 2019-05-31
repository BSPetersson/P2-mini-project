#ifndef STORY_H
#define STORY_H

#include "ledlight.h"
#include "readwrite.h"

class Story : public LEDLight, public ReadWrite
{
public:
    Story();

    int place = 1;
    int storyLine[12][3] = {{4,2,0},{3,11,0},{14,14,14},{6,5,0},{11,12,0},{8,14,5},{14,14,0},{10,9,0},{14,14,0},{10,10,10},{12,8,0},{2,4,0}};

    void next();
    void actions(int storyIndex);
};

#endif // STORY_H
