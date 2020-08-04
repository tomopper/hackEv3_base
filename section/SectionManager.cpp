#include "SectionManager.h"

SectionManager::SectionManager()
{
    mSectionIdx=0;
    mLastIdx=0;
 
}

bool SectionManager::run()
{
    return true;
}

void SectionManager::addSection(Section *sec)
{
    mSection[mLastIdx++]=sec;
}

void SectionManager::reset()
{
    mSectionIdx = 0;
    mLastIdx=0;
}

