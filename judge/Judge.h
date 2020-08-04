#ifndef _JUDGE_H_
#define _JUDGE_H_

#include "HsvHue.h" 
#include "HsvSatu.h"
#include "Brightness.h"
#include "Length.h"
#include "TurnAngle.h"

class Judge{
    public:
    Judge();
    virtual bool run();

    protected:
    HsvHue *mHsvHue;
    HsvSatu *mHsvSatu;
    Brightness *mBrightness;
    Length *mLength;
    TurnAngle *mTurnAngle;



};


#endif