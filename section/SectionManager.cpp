#include "SectionManager.h"

SectionManager::SectionManager()
{

    mSectionIdx=0;
    mLastIdx=0;
 
}

SectionManager::~SectionManager()
{


    for(int i=0;i<mLastIdx;i++) {
        delete mSection[i];
    }
}

bool SectionManager::run()
{
    //msg_f("aaaa",5);
    if(mSection[mSectionIdx]==nullptr)
    {
        //msg_f("true",5);
        return true;
    }
        //return true;

  //  if(mSectionIdx==0)
    // msg_log("0");
    //if(mSectionIdx==1)
    // msg_log("1");
    if(mSection[mSectionIdx]->run())
    {
        mSectionIdx++;
        //msg_f("end",4);
    }
        //mSectionIdx++;

    return false;
}

void SectionManager::addSection(Section *sec)
{


    mSection[mLastIdx++]=sec;
    mSection[mLastIdx]=nullptr;
}

void SectionManager::reset()
{
    for(int i=0;i<mLastIdx;i++) {
        delete mSection[i];
        msg_f("delete",3);
    }
    mSectionIdx = 0;
    mLastIdx=0;
}

