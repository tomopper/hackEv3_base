#include "HsvHue.h"

HsvHue::HsvHue()
    : Measure()
{

}

float HsvHue::getValue()
{
    return mHue;
}

void HsvHue::update(float h)
{
    mHue = h;
}