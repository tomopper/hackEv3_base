#include "SpeedSectionManager.h"

SpeedSectionManager::SpeedSectionManager()
{
    //test 
}

bool SpeedSectionManager::run()
{
    if(mSection[mSectionIdx].run())
        return true;

    return false;
}