#include "LengthJudge.h"
#include "util.h"
#include "global.h"
#include "HBTtask.h"


extern float gStart;

LengthJudge::LengthJudge()
{

    float mStartlength = 0;
    float mFinishlength = 0;
}
void LengthJudge::setFinLength2()
{
    mFinishlength = mFinishlength + mStartlength;
}


void LengthJudge::setFinLength(float finlength)
{
    //終了値

    mFinishlength = finlength;
     
}
bool LengthJudge::run()
{
    if (mFinishlength > mStartlength)
    //if(1<2)
    {
        if (mLength->getValue() >= mFinishlength)
        {
            return true;
        }
        else
        {
            if (getSendchar() == 'R')
            {
                setSendchar(0);
                return true;
            }
            else if(getSendchar() == 'B')
            {
                setSendchar(0);
                return true;
            }
        return false;
        }
    }
    /*else{
        if (mLength->getValue() < mFinishlength)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    */
}

void LengthJudge::init()
{
    if(update == Judge::UPDATE){
        gStart = mLength->getValue(); // 更新
        mStartlength=mLength->getValue();
        mFinishlength = mFinishlength + gStart; // 現在地からの距離
    }
    else{
    
        mStartlength=mLength->getValue();
        mFinishlength = mFinishlength + gStart; //　以前の値からの距離
    }
    // syslog(LOG_NOTICE,"LengthJudge::init %d,%d",(int)mStartlength,(int)mFinishlength);

}

void LengthJudge::setupdate(Judge::JUDGE_MODE a){
        update=a;

}