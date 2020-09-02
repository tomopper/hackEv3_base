#include "ArmAngleJudge.h"
#include "util.h"

ArmAngleJudge::ArmAngleJudge()
{
    mStartAngle = 0.0;
    mFinAngle = 0.0;
}

void ArmAngleJudge::init()
{
    mStartAngle = mArmAngle->getValue();
}

void ArmAngleJudge::setFinAngle(float finangle)
{
    mFinAngle = mStartAngle + finangle;
}

bool ArmAngleJudge::run()
{
    /*static char buf[256];
    sprintf(buf," %f",mArmAngle->getValue());
    msg_log(buf);*/
    if(mFinAngle >= mStartAngle)
    {
        if(mFinAngle <= mArmAngle->getValue())
        {
            return true;
        }
    }
    else{
        if(mFinAngle >= mArmAngle->getValue())
        {
            return true;
        }
    }

    return false;
}