#include "Judge.h"




extern HsvHue *gHue;
extern HsvSatu *gSatu;
extern Brightness *gBrightness;
extern Length *gLength;
extern TurnAngle *gTurnAngle;
extern TailAngle *gTailAngle;
extern ArmAngle *gArmAngle;
extern GyroAngle *gGyroAngle;

Judge::Judge(){
    mHsvHue = gHue;
    mHsvSatu = gSatu;
    mBrightness = gBrightness;
    mLength = gLength;
    mTurnAngle = gTurnAngle;
    mTailAngle = gTailAngle;
    mArmAngle = gArmAngle;
    mGyroAngle = gGyroAngle;

}

bool Judge::run(){
    return true;
}

void Judge::init(){

    
}



