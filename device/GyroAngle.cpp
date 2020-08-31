#include "GyroAngle.h"

GyroAngle::GyroAngle()
    :Measure()
{

}

float GyroAngle::getValue()
{
    return gAng;
}

void GyroAngle::update(float ga)
{
    gAng = ga;
}