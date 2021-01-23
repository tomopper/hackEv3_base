#include "LengthJudge.h"
#include "util.h"
#include "global.h"

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

char sendchar;

void LengthJudge::setFinLength(float finlength)
{
    //終了値

    mFinishlength = finlength;
     
}
bool LengthJudge::run()
{

    if (mFinishlength > mStartlength)
    {
    
        /*if (mLength->getValue() >= mFinishlength)
        {
            return false;
        }
        else
        {
            return false;
        }*/
        if (sendchar == 'R')
        {
            return true; //trueじゃなくて何秒間かモーター停止させる
        }
        else if(sendchar == 'B')
        {
            return true;
        }
        else
        {
            return false;
            msg_f("runrun",4);
        }
    }
    /*else
    {
        if (mLength->getValue() < mFinishlength) //赤を見つけた時に何秒か停止
        {
            return true;
        }
        else{
            return false;
        }
    }*/
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