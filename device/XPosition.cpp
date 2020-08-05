#include "XPosition.h"

XPosition::XPosition()
    : Measure()
{
}

double XPosition::getvalue()
{
    return mXPosition;
}

void XPosition::update(double x)
{
    mXPosition = x;
}
