#include "LengthJudge.h"
#include "util.h"

LengthJudge::LengthJudge()
{

    float mStartlength = 0;
    float mFinishlength = 0;
}
void LengthJudge::setStartLength()
{}

void LengthJudge::setFinLength(float finlength)
{
    //終了値

    mFinishlength = finlength + mStartlength;
}
bool LengthJudge::run()
{

    if(mFinishlength>mStartlength){
        if (mLength->getValue() >=  mFinishlength)
        {
            return true;
        }
        else
        {
            return false;
     
        }
    }
    else{
        if (mLength->getValue() <=  mFinishlength)
        {
            return true;
        }
        else
        {
            return false;
     
        }
    }
    return true;
}

void LengthJudge::init(){

    mStartlength = mLength->getValue();
    mFinishlength += mStartlength;

static char buf[256];
    sprintf(buf,"LengthJudge::init %f,%f",mStartlength,mFinishlength);
    msg_log(buf);
}

