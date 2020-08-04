#ifndef _BRIGHTNESSJUDGE_H_
#define _BRIGHTNESSJUDGE_H_

#include "Judge.h"

class BrightnessJudge:public Judge{
    public :
    BrightnessJudge();
    void setBrightness();
    bool run();

    private :
    float brigtness;


};



#endif