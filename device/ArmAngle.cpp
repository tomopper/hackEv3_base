#include "ArmAngle.h"

ArmAngle::ArmAngle():
    Measure()
{
}

float ArmAngle::getValue()
{
    return mArmAngle;
}

void ArmAngle::update(float arm)
{
    mArmAngle = arm;
}