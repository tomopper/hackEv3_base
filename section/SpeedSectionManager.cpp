#include "SpeedSectionManager.h"

SpeedSectionManager::SpeedSectionManager()
{
    
}

bool SpeedSectionManager::run()
{
    if(mSection[mSectionIdx].run())
        return true;

    return false;
}