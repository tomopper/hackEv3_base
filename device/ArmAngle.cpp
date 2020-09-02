#include "ArmAngle.h"

ArmAngle::ArmAngle():
    Measure()
{
}

float ArmAngle::getValue()
{
    // return mArmAngle;
    return mLpf->getFillteredValue();
}

void ArmAngle::update(float arm)
{
    mLpf->addValue(arm);
    mArmAngle = arm;
}