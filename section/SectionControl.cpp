#include "SectionControl.h"

SectionControl::SectionControl()
{
    mSectionIdx=0;
    mLastIdx=0;
 
}

bool SectionControl::run()
{
    return true;
}

void SectionControl::addSection(Section *sec)
{
    mSection[mLastIdx++]=*sec;
}

void SectionControl::reset()
{
    mSectionIdx = 0;
    mLastIdx=0;
}

