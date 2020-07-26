#include "Measure.h"

Measure::Measure()
{
    mLpf = new LowPassFilter();
}

float Measure::getValue()
{
    return 0;
}