#include "Judge.h"


    const int Judge::UPDATE = true;
    const int Judge::UNUPDATE = false;

extern HsvHue *gHue;
extern HsvSatu *gSatu;
extern Brightness *gBrightness;
extern Length *gLength;
extern TurnAngle *gTurnAngle;

Judge::Judge(){
    mHsvHue = gHue;
    mHsvSatu = gSatu;
    mBrightness = gBrightness;
    mLength = gLength;
    mTurnAngle = gTurnAngle;



}

bool Judge::run(){
    return true;
}

void Judge::init(){

    
}



