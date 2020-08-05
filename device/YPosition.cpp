#include "YPosition.h"

YPosition::YPosition()
    : Measure()
{
}

double YPosition::getvalue()
{
    return mYPosition;
}

void YPosition::update(double y)
{
    mYPosition = y;
}
