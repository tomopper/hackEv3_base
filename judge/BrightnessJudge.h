#ifndef _BRIGHTNESSJUDGE_H_
#define _BRIGHTNESSJUDGE_H_

#include "Judge.h"

class BrightnessJudge:public Judge{
    public :
    BrightnessJudge();
    void setBrightness(float x, int i);
    bool run();

    private :
    float brigtness;
    int flag;

};



#endif