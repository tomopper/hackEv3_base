#include "Brightness.h"

Brightness::Brightness()
    : Measure()
{

}

float Brightness::getValue()
{
    return mBrightness;
}

void Brightness::update(float br)
{
    mBrightness = br;
}