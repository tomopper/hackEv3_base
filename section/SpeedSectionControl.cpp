#include "SpeedSectionControl.h"

SpeedSectionControl::SpeedSectionControl()
{
    
}

bool SpeedSectionControl::run()
{
    if(mSection[mSectionIdx].run())
        return true;

    return false;
}